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

static void	write_fd(int fd, t_redir **redirection, char *creat_in_tmp,
		t_shellvar *vars)
{
	char	*str;
	int		vld;

	vld = 0;
	if ((*redirection)->red_mode == heredoc_expand)
		vld = 1;
	str = readline("heredoc> ");
	while (str && ft_strcmp(str, (*redirection)->filename) != 0)
	{
		if (vld == 1)
			write(fd, str, ft_strlen(str));
		else
			write(fd, replace(str, vars), ft_strlen(replace(str, vars)));
		write(fd, "\n", 1);
		free(str);
		str = readline("heredoc> ");
	}
	free(str);
	close(fd);
	free((*redirection)->filename);
	(*redirection)->filename = creat_in_tmp;
}

static void	write_files_heredoc(t_redir *redirections, int *index,
		t_shellvar *vars)
{
	t_redir	*tmp_redirections;
	char	*namefile;
	char	*creat_in_tmp;
	int		fd;
	char	*index_str;

	tmp_redirections = redirections;
	while (tmp_redirections != NULL && (tmp_redirections->red_mode == heredoc
			|| tmp_redirections->red_mode == heredoc_expand))
	{
		index_str = ft_itoa((*index)++);
		namefile = triplejoin(tmp_redirections->filename, "-heredoc-",
				index_str);
		free(index_str);
		creat_in_tmp = ft_strjoin("/tmp/", namefile);
		fd = open(creat_in_tmp, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			perror("open");
		else
			write_fd(fd, &tmp_redirections, creat_in_tmp, vars);
		free(namefile);
		tmp_redirections = tmp_redirections->next;
	}
}

void	prepare_heredocs(t_command *cmds, t_shellvar *vars)
{
	t_command	*tmp_cmds;
	int			index;

	tmp_cmds = cmds;
	index = 0;
	while (tmp_cmds != NULL)
	{
		write_files_heredoc(tmp_cmds->redirections, &index, vars);
		tmp_cmds = tmp_cmds->next;
	}
}
