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

int	cd(t_command *command, t_shellvar *vars)
{
	char	*path;
	char	*old;

	if (matrixlen(command->args) > 2)
		return (ft_putstr_fd("cd: too many arguments\n", STDERR_FILENO), 1);
	else if (matrixlen(command->args) == 1)
	{
		path = getvar("HOME", vars);
		if (!path)
			return (ft_putstr_fd("cd: $HOME not set\n", STDERR_FILENO), 1);
	}
	else if (!my_strcmp(command->args[1], "-"))
		path = getvar("OLDPWD", vars);
	else
		path = command->args[1];
	old = getcwd(NULL, 0);
	if (chdir(path) != 0)
		return (perror("cd"), 1);
	updatevar("PWD", path, vars, true);
	updatevar("OLDPWD", old, vars, true);
	free(old);
	return (0);
}
