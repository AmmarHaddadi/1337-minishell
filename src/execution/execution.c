#include "execution.h"
#include "../main.h"
#include <sys/wait.h>
#include <unistd.h>

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
	// else if (!my_strcmp("exit", cmd->args[0]))
	// return true;
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
		return unset(cmd, vars);
	else if (!my_strcmp("env", cmd->args[0]))
		return env(vars);
	// TODO: need to free shit before exit, talk w salah
	// else if (!my_strcmp("exit", cmd->args[0]))
	// return builtin_exit(cmd);
	return 0;
}

// returns the exit code
int execute(t_command *cmd, t_shellvar *vars) {
	if (isbltn(cmd))
		return execbltn(cmd, vars);
	char *path = getvalidpath(cmd, getvar("PATH", vars));
	if (!path)
		return 127;
	pid_t pid = fork();
	if (pid == -1)
		return (perror("could't fork"), free(path), -1);
	if (pid == 0) {
		char **env = varstomatrix(vars);
		execve(path, cmd->args, env);
		perror("command failed");
		freematrix(env);
		exit(-1);
	}
	int stat;
	waitpid(pid, &stat, 0);
	if (WIFEXITED(stat) == 0)
		return (ft_putstr_fd("child exited unexpectedly", STDERR_FILENO), -1);
	return WEXITSTATUS(stat);
}
