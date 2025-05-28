#include "../main.h"

bool isbltn(t_command *cmd) {
	if (!my_strcmp("echo", cmd->args[0]))
		return true;
	else if (!my_strcmp("cd", cmd->args[0]))
		return true;
	else if (!my_strcmp("pwd", cmd->args[0]))
		return true;
	else if (!my_strcmp("export", cmd->args[0]))
		return true;
	else if (!my_strcmp("unset", cmd->args[0]))
		return true;
	else if (!my_strcmp("env", cmd->args[0]))
		return true;
	else if (!my_strcmp("exit", cmd->args[0]))
		return true;
	return false;
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
	// TODO: need to free shit before exit, talk w salah
	// else if (!my_strcmp("exit", cmd->args[0]))
	// return builtin_exit(cmd);
	return 0;
}

// NOTE if there is a redir, write to it not the pipe
// returns the exit code
int bin(t_command *cmd, t_shellvar *vars) {
	if (!setupfd(cmd->redirections))
		return (ft_putstr_fd("can't setup fd\n", STDERR_FILENO), 1);
	if (isbltn(cmd))
		exit(execbltn(cmd, vars));
	char *path = getvalidpath(cmd, getvar("PATH", vars));
	if (!path)
		return (ft_putstr_fd("bin not found\n", STDERR_FILENO), 127);
	char **env = varstomatrix(vars);
	if (!env)
		return (ft_putstr_fd("err env\n", STDERR_FILENO), free(path), 127);
	execve(path, cmd->args, env);
	perror("execution failed");
	freematrix(env);
	free(path);
	return 126;
}

int maestro(t_command *cmd, t_shellvar *vars) {
	int clen = cmdlen(cmd);
	int ret = 0;
	int stat;
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
	for (int i = 0; i < clen; i++) {
		waitpid(pids[i], &stat, 0);
		if (WIFEXITED(stat) == 0) {
			// ft_putstr_fd("child exited unexpectedly\n", STDERR_FILENO);
			ret = -1;
		} else {
			if (i == clen - 1)
				ret = WEXITSTATUS(stat);
		}
	}
	freepipes(pipes, clen - 1);
	free(pids);
	return ret;
}
