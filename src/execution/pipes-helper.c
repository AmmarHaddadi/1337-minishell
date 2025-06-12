/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes-helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 23:07:44 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/06/09 23:07:44 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

int	**setuppipes(int len)
{
	int	**pipes;
	int	i;

	i = 0;
	pipes = malloc(len * sizeof(int *));
	if (!pipes)
		return (NULL);
	while (i < len)
	{
		pipes[i] = malloc(2 * sizeof(int));
		if (!pipes[i])
			return (fcp(pipes, i), NULL);
		if (pipe(pipes[i]) == -1)
			return (fcp(pipes, i), free(pipes[i]), NULL);
		i++;
	}
	return (pipes);
}

int	cmdlen(t_command *cmd)
{
	int	i;

	i = 0;
	while (cmd != NULL)
	{
		i++;
		cmd = cmd->next;
	}
	return (i);
}

// freeclosepipes
void	fcp(int **pipes, int len)
{
	int	i;

	if (!pipes)
		return ;
	i = 0;
	while (i < len)
	{
		if (pipes[i])
		{
			close(pipes[i][0]);
			close(pipes[i][1]);
			free(pipes[i]);
		}
		i++;
	}
	free(pipes);
}

// closepipes
void	cp(int **pipes, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}
// void freepipes(int **pipes, int max) {
// 	int i = 0;
// 	while (i < max) {
// 		free()
// 	}
// }
