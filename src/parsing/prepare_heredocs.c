/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_heredocs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:03:02 by ssallami          #+#    #+#             */
/*   Updated: 2025/06/20 20:40:14 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	handle_heredoc_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
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

static int	handle_heredoc_process(t_redir **redir, char *tmpfile, int fd,
		t_shellvar *vars)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		close(fd);
		unlink(tmpfile);
		return (-1);
	}
	else if (pid == 0)
		write_fd(fd, redir, tmpfile, vars);
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	signal(SIGINT, SIG_DFL);
	close(fd);
	if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
	{
		unlink(tmpfile);
		free(tmpfile);
		return (-1);
	}
	return (0);
}

static char	*generate_tmpfile(t_redir *redir, int *index)
{
	char	*index_str;
	char	*namefile;
	char	*tmpfile;

	index_str = ft_itoa((*index)++);
	if (!index_str)
		return (NULL);
	namefile = triplejoin(redir->filename, "-heredoc-", index_str);
	free(index_str);
	if (!namefile)
		return (NULL);
	tmpfile = ft_strjoin("/tmp/", namefile);
	free(namefile);
	return (tmpfile);
}

static void	write_files_heredoc(t_redir **redirections, int *index,
		t_shellvar *vars)
{
	t_redir	*tmp_redirections;
	char	*tmpfile;
	int		fd;

	tmp_redirections = *redirections;
	while (tmp_redirections && (tmp_redirections->red_mode == heredoc
			|| tmp_redirections->red_mode == heredoc_expand))
	{
		tmpfile = generate_tmpfile(tmp_redirections, index);
		// if (!tmpfile)
		// 	return (1);
		fd = open(tmpfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror("open");
			free(tmpfile);
			tmp_redirections = tmp_redirections->next;
			continue ;
		}
		if (handle_heredoc_process(&tmp_redirections, tmpfile, fd, vars) < 0)
			{
				tmp_redirections->filename = NULL;
				return ;}
		free(tmp_redirections->filename);
		tmp_redirections->filename = tmpfile;
		tmp_redirections = tmp_redirections->next;
	}
}

void	prepare_heredocs(t_command *cmds, t_shellvar *vars)
{
	t_command	*tmp_cmds;
	int			index;

	tmp_cmds = cmds;
	index = 0;
	while (tmp_cmds)
	{
		write_files_heredoc(&tmp_cmds->redirections, &index, vars);
		tmp_cmds = tmp_cmds->next;
	}
}
