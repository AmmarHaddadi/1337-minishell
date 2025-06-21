/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setupfds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 00:08:27 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/06/21 16:45:22 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

// creates outfiles
static bool	createoutfiles(t_redir *red)
{
	int	fd;

	while (red != NULL)
	{
		if (red->red_mode == override || red->red_mode == append)
		{
			fd = open(red->filename, O_CREAT, 0644);
			if (fd < 0)
				return (false);
			close(fd);
		}
		red = red->next;
	}
	return (true);
}

// sets the out file and mode
static void	setout(t_redir *redir, char **redfile, int *outmode)
{
	while (redir != NULL)
	{
		if (redir->red_mode == override)
		{
			*redfile = redir->filename;
			*outmode = O_TRUNC;
		}
		else if (redir->red_mode == append)
		{
			*redfile = redir->filename;
			*outmode = O_APPEND;
		}
		redir = redir->next;
	}
}

static void	setin(t_redir *redir, char **redfile)
{
	while (redir != NULL)
	{
		if (redir->red_mode == in || redir->red_mode == heredoc
			|| redir->red_mode == heredoc_expand)
		{
			*redfile = redir->filename;
			break ;
		}
		redir = redir->next;
	}
}

bool	setupfd(t_redir *red)
{
	char	*redfile;
	int		outmode;
	int		ofd;
	int		ifd;

	if (!red)
		return (true);
	if (!createoutfiles(red))
		return (false);
	redfile = NULL;
	setout(red, &redfile, &outmode);
	if (!routeout(&ofd, outmode, redfile))
		return (false);
	redfile = NULL;
	setin(red, &redfile);
	if (!redfile)
		return (true);
	ifd = open(redfile, O_RDONLY);
	if (ifd < 0)
		return (perror("Can't open input file"), close(ofd), false);
	if (dup2(ifd, STDIN_FILENO) < 0)
		return (perror("Can't read input"), close(ofd), close(ifd), false);
	return (true);
}
