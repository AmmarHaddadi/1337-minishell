#include "../main.h"

int echo(t_command *cmd) {
	if (matrixlen(cmd->args) < 2)
		return 0;
	int i = 1;
	int n = my_strcmp(cmd->args[1], "-n");
	if (n == 0)
		i += 1;
	while (cmd->args[i]) {
		ft_putstr_fd(cmd->args[i], STDOUT_FILENO);
		if (cmd->args[i + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	if (n != 0)
		write(1, "\n", 1);
	return 0;
}
