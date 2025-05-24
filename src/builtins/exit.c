#include "../main.h"
// code >=0 ? free and exit(code) : set last code to 1

int builtin_exit(t_command *cmd) {
	if (cmd->args[2] != NULL)
		return (ft_putstr_fd("Too many arguments", STDERR_FILENO), -1);
	int i = 1;
	// if wrong code exit 255
	while (cmd->args[1][i]) {
		if (!ft_isdigit(cmd->args[1][i]))
			return (255);
		i++;
	}
	// first char not +- or 0-9
	if (!ft_isdigit(cmd->args[1][0]) && cmd->args[1][0] != '+' &&
		cmd->args[1][0] != '-')
		return (255);
	return ft_atoi(cmd->args[1]) % 255;
}
