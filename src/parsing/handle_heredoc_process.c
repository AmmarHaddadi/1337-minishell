/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc_process.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:24:39 by ssallami          #+#    #+#             */
/*   Updated: 2025/06/23 17:24:44 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	handle_heredoc_sigint(int sig)
{
	(void)sig;
	exit(130);
}

static void	write_fd(int fd, t_redir **redirection, char *creat_in_tmp,
		t_shellvar *vars)
{
	char	*str;
	char	*tmp;

	signal(SIGINT, handle_heredoc_sigint);
	str = readline("heredoc> ");
	while (str && ft_strcmp(str, (*redirection)->filename) != 0)
	{
		if ((*redirection)->red_mode != heredoc_expand)
		{
			tmp = str;
			str = replace(tmp, vars);
			free(tmp);
		}
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
		free(str);
		str = readline("heredoc> ");
	}
	free(str);
	close(fd);
	free(creat_in_tmp);
	exit(0);
}

int	handle_heredoc_process(t_redir **redir, char *tmpfile, int fd,
		t_shellvar *vars)
{
	pid_t	pid;
	int		status;

	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid < 0)
	{
		close(fd);
		return (perror("heredoc fork"), unlink(tmpfile), -1);
	}
	else if (pid == 0)
		write_fd(fd, redir, tmpfile, vars);
	waitpid(pid, &status, 0);
	signal(SIGINT, handle_ctrlc);
	close(fd);
	if (WIFSIGNALED(status) || !WIFEXITED(status) || WEXITSTATUS(status) != 0)
	{
		unlink(tmpfile);
		free(tmpfile);
		free((*redir)->filename);
		return (-1);
	}
	return (0);
}
