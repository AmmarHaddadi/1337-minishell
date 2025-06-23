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

// 0 -> conti to next
// 1 -> return
static int	hrdcstp(t_redir *tmp_red, int *index, t_shellvar *vars)
{
	int		fd;
	char	*tmpfile;

	if (!(tmp_red->red_mode == heredoc || tmp_red->red_mode == heredoc_expand))
		return (0);
	tmpfile = generate_tmpfile(tmp_red, index);
	fd = open(tmpfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open");
		free(tmpfile);
		tmp_red = tmp_red->next;
		return (0);
	}
	if (handle_heredoc_process(&tmp_red, tmpfile, fd, vars) < 0)
	{
		tmp_red->filename = NULL;
		return (1);
	}
	free(tmp_red->filename);
	tmp_red->filename = tmpfile;
	return (0);
}

static void	write_files_heredoc(t_redir **redirections, int *index,
		t_shellvar *vars)
{
	t_redir	*tmp_red;

	tmp_red = *redirections;
	while (tmp_red)
	{
		if (hrdcstp(tmp_red, index, vars) == 1)
			break ;
		tmp_red = tmp_red->next;
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
