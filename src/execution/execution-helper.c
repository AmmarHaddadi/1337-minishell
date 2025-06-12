/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution-helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 23:07:44 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/06/09 23:07:44 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

// returns the first path where the binary exists
char	*getvalidpath(t_command *cmd, char *path)
{
	char	**paths;
	char	*valid;
	char	*joined;
	int		i;

	paths = ft_split(path, ':');
	valid = NULL;
	if (paths)
	{
		i = 0;
		while (paths[i] && valid == NULL)
		{
			joined = triplejoin(paths[i++], "/", cmd->args[0]);
			if (access(joined, X_OK) == 0)
				valid = ft_strdup(joined);
			free(joined);
		}
		freematrix(paths);
	}
	if (!valid && access(cmd->args[0], X_OK) == 0)
		valid = ft_strdup(cmd->args[0]);
	return (valid);
}

static void	freeredirs(t_redir *red)
{
	t_redir	*prvs;

	while (red != NULL)
	{
		prvs = red;
		red = red->next;
		free(prvs->filename);
		free(prvs);
	}
}

void	freecmd(t_command *cmd)
{
	t_command	*prvs;

	while (cmd != NULL)
	{
		prvs = cmd;
		cmd = cmd->next;
		freematrix(prvs->args);
		freeredirs(prvs->redirections);
		free(prvs);
	}
}

void	hndlfrkerr(int i, int clen, int *pids, int **pipes)
{
	int	j;

	j = 0;
	while (j < i)
		kill(pids[j++], SIGTERM);
	fcp(pipes, clen - 1);
	free(pids);
	perror("fork problem");
}
