#include "../main.h"

int	builtin_exit(t_command *cmd)
{
	int	i;

	if (matrixlen(cmd->args) > 2)
		return (ft_putstr_fd("Too many arguments\n", STDERR_FILENO), 1);
	// first char not +- or 0-9 -> exit 255
	if (!ft_isdigit(cmd->args[1][0]) && cmd->args[1][0] != '+'
		&& cmd->args[1][0] != '-')
		return (255);
	// exit code not numeric -> exit 255
	i = 1;
	while (cmd->args[1][i])
	{
		if (!ft_isdigit(cmd->args[1][i]))
			return (255);
		i++;
	}
	return (ft_atoi(cmd->args[1]) % 255);
}

// checks for exit in the LL
void	set_xt(t_command *cmd, int *xt)
{
	while (cmd)
	{
		if (cmd->args == NULL || cmd->args[0] == NULL)
		{
			cmd = cmd->next;
			continue ;
		}
		else if (!my_strcmp(cmd->args[0], "exit"))
		{
			*xt = true;
			return ;
		}
		cmd = cmd->next;
	}
}
