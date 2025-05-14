#include "../main.h"

/* 	NOTE
	in bash, `cd path1 path2 path3` takes u to path1
	in ZSH it errors: too many arguments, and exit(1)
	reimplementing a Bash bug disguised as a "feature" is dumb
 */

int cd(t_command *command) {
	// too much args
	if (matrixlen(command->args) > 2) {
		ft_putstr_fd("cd: too many arguments\n", STDERR_FILENO);
		return 1;
	}
	// `cd`
	if (matrixlen(command->args) == 1) {
		if (!getenv("HOME"))
			return (ft_putstr_fd("cd: $HOME not set\n", STDERR_FILENO), 1);
		if (chdir(getenv("HOME")) != 0) {
			perror("cd");
			return 1;
		}
		return 0;
	}
	// `cd dir`
	if (chdir(command->args[1]) != 0) {
		perror("cd");
		return 1;
	}
	return 0;
}
