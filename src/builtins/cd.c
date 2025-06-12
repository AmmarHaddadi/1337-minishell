/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 21:39:41 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/06/07 21:39:41 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

/* 	NOTE
	in bash, `cd path1 path2 path3` takes u to path1
	in ZSH it errors: too many arguments, and exit(1)
	reimplementing a Bash bug disguised as a "feature" is dumb
 */

int	cd(t_command *command, char *home)
{
	if (matrixlen(command->args) > 2)
	{
		ft_putstr_fd("cd: too many arguments\n", STDERR_FILENO);
		return (1);
	}
	if (matrixlen(command->args) == 1)
	{
		if (!home)
			return (ft_putstr_fd("cd: $HOME not set\n", STDERR_FILENO), 1);
		if (chdir(home) != 0)
		{
			perror("cd");
			return (1);
		}
		return (0);
	}
	if (chdir(command->args[1]) != 0)
	{
		perror("cd");
		return (1);
	}
	return (0);
}
