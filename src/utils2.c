/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:17:08 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/06/23 15:17:08 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

// is heredoc fkup ret true
bool	thatonecase(t_command *cmd)
{
	t_redir	*red;

	if (!cmd)
		return (false);
	red = cmd->redirections;
	while (red)
	{
		if (red->filename == NULL && (red->red_mode == heredoc
				|| red->red_mode == heredoc_expand))
			return (true);
		red = red->next;
	}
	return (false);
}
