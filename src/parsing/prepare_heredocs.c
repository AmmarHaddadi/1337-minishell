/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_heredocs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:03:02 by ssallami          #+#    #+#             */
/*   Updated: 2025/06/23 17:25:26 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

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

static int	check_heredoc(t_redir *tmp_redirections)
{
	return (tmp_redirections && (tmp_redirections->red_mode == heredoc
			|| tmp_redirections->red_mode == heredoc_expand));
}

static void	write_files_heredoc(t_redir **redirections, int *index,
		t_shellvar *vars)
{
	t_redir	*tmp_redirections;
	char	*tmpfile;
	int		fd;

	tmp_redirections = *redirections;
	while (check_heredoc(tmp_redirections))
	{
		tmpfile = generate_tmpfile(tmp_redirections, index);
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
			return ;
		}
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
