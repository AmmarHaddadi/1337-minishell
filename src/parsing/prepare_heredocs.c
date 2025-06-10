/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_heredocs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:03:02 by ssallami          #+#    #+#             */
/*   Updated: 2025/06/09 21:05:19 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static void	write_fd(int fd, char *filename)
{
	char	*str;

	str = readline("heredoc> ");
	while (str && ft_strcmp(str, filename) != 0)
	{
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
		free(str);
		str = readline("heredoc> ");
	}
	free(str);
}

static void	write_files_heredoc(t_redir *redirections, int *index)
{
	t_redir	*tmp_redirections;
	char	*namefile;
	char	*creat_in_tmp;
	int		fd;
	char	*index_str;
	char	*tmp;

	tmp_redirections = redirections;
	while (tmp_redirections != NULL)
	{
		if (tmp_redirections->red_mode == heredoc)
		{
			index_str = ft_itoa((*index)++);
			tmp = ft_strjoin(tmp_redirections->filename, "-heredoc-");
			namefile = ft_strjoin(tmp, index_str);
			free(index_str);
			free(tmp);
			creat_in_tmp = ft_strjoin("/tmp/", namefile);
			fd = open(creat_in_tmp, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (fd == -1)
				perror("open");
			else
			{
				write_fd(fd, tmp_redirections->filename);
				close(fd);
			}
			free(namefile);
			free(tmp_redirections->filename);
			tmp_redirections->filename = creat_in_tmp;
		}
		tmp_redirections = tmp_redirections->next;
	}
}

void	prepare_heredocs(t_command *cmds)
{
	t_command	*tmp_cmds;
	int			index;

	tmp_cmds = cmds;
	index = 0;
	while (tmp_cmds != NULL)
	{
		write_files_heredoc(tmp_cmds->redirections, &index);
		tmp_cmds = tmp_cmds->next;
	}
}
