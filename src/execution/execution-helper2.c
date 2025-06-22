/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution-helper2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:21:45 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/06/12 16:21:45 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

int	getcode(int *pids, int clen)
{
	int	stat;
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (i < clen)
	{
		waitpid(pids[i], &stat, 0);
		if (i == clen - 1)
			ret = WEXITSTATUS(stat);
		i++;
	}
	return (ret);
}

int	dofork(struct s_maestro ms, int i, t_command *cmd, t_shellvar *vars)
{
	ms.pids[i] = fork();
	if (ms.pids[i] == -1)
		return (hndlfrkerr(i, ms.clen, ms.pids, ms.pipes), 1);
	if (ms.pids[i] == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, SIG_DFL);
		if (i < ms.clen - 1)
			dup2(ms.pipes[i][1], STDOUT_FILENO);
		if (i > 0)
			dup2(ms.pipes[i - 1][0], STDIN_FILENO);
		cp(ms.pipes, ms.clen - 1);
		bin(cmd, vars);
	}
	return (0);
}
