#include "../main.h"

// 0 -> no
// 1 -> bltn
// 2 -> execute in-shell
static int isbltn(t_command *cmd) {
	if (cmd->args == NULL || cmd->args[0] == NULL)
		return 0;
	if (!my_strcmp("echo", cmd->args[0]))
		return 1;
	else if (!my_strcmp("cd", cmd->args[0]))
		return 2;
	else if (!my_strcmp("pwd", cmd->args[0]))
		return 2;
	else if (!my_strcmp("export", cmd->args[0]))
		return 2;
	else if (!my_strcmp("unset", cmd->args[0]))
		return 2;
	else if (!my_strcmp("env", cmd->args[0]))
		return 1;
	else if (!my_strcmp("exit", cmd->args[0]))
		return 1;
	return 0;
}

int execbltn(t_command *cmd, t_shellvar *vars) {
	if (!my_strcmp("echo", cmd->args[0]))
		return echo(cmd);
	else if (!my_strcmp("cd", cmd->args[0]))
		return cd(cmd, getvar("HOME", vars));
	else if (!my_strcmp("pwd", cmd->args[0]))
		return pwd();
	else if (!my_strcmp("export", cmd->args[0]))
		return export(vars, cmd);
	else if (!my_strcmp("unset", cmd->args[0]))
		return unset(cmd, &vars);
	else if (!my_strcmp("env", cmd->args[0]))
		return env(vars);
	else if (!my_strcmp("exit", cmd->args[0]))
		return builtin_exit(cmd);
	return 0;
}

// NOTE if there is a redir, write to it not the pipe
// NOTE this is it's own fork, so exit, not return
// QUESTION for norme, can I return(f1(), exit(code), 1) ??
// technically I need to free vars and cmd too...
int bin(t_command *cmd, t_shellvar *vars) {
	if (!setupfd(cmd->redirections)) {
		ft_putstr_fd("can't setup fd\n", STDERR_FILENO);
		exit(1);
	}
	if (isbltn(cmd))
		exit(execbltn(cmd, vars));
	char *path = getvalidpath(cmd, getvar("PATH", vars));
	if (!path) {
		ft_putstr_fd("bin not found\n", STDERR_FILENO);
		exit(127);
	}
	char **env = varstomatrix(vars);
	if (!env) {
		ft_putstr_fd("err env\n", STDERR_FILENO);
		free(path);
		exit(127);
	}
	execve(path, cmd->args, env);
	perror("execution failed");
	freematrix(env);
	free(path);
	exit(126);
}

int maestro(t_command *cmd, t_shellvar *vars, int *xt) {
	int clen = cmdlen(cmd);
	// if "exit" found in LL -> toggle on exit mode
	set_xt(cmd, xt);
	if (isbltn(cmd) == 2 && clen == 1)
		return execbltn(cmd, vars);
	pid_t *pids = malloc(clen * sizeof(pid_t)); // Array to store PIDs
	if (!pids)
		return (perror("pid array allocation failed"), 1);

	int **pipes = setuppipes(clen - 1);
	if (!pipes)
		return (perror("pipes problem"), free(pids), 1);

	// Fork all processes
	t_command *current_cmd = cmd;
	for (int i = 0; i < clen; i++) {
		pids[i] = fork();

		if (pids[i] == -1) {
			// Handle fork failure - free and kill
			for (int j = 0; j < i; j++)
				kill(pids[j], SIGTERM);
			freepipes(pipes, clen - 1);
			free(pids);
			return (perror("fork prblm"), 1);
		}

		if (pids[i] == 0) {
			// write to current pipe read from previous
			if (i < clen - 1)
				dup2(pipes[i][1], STDOUT_FILENO);
			if (i > 0)
				dup2(pipes[i - 1][0], STDIN_FILENO);

			// NOTE it's ok the old STDFDs are doing the job
			for (int j = 0; j < clen - 1; j++) {
				close(pipes[j][0]);
				close(pipes[j][1]);
			}

			bin(current_cmd, vars);
		}
		current_cmd = current_cmd->next;
	}

	// close all pipes in parent process;
	for (int i = 0; i < clen - 1; i++) {
		close(pipes[i][0]);
		close(pipes[i][1]);
	}

	// waiting for processes to fininsh
	int ret = 0;
	int stat;
	for (int i = 0; i < clen; i++) {
		waitpid(pids[i], &stat, 0);
		if (i == clen - 1)
			ret = WEXITSTATUS(stat);
	}
	freepipes(pipes, clen - 1);
	free(pids);
	return ret;
}
