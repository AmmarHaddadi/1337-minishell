/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 08:19:21 by ssallami          #+#    #+#             */
/*   Updated: 2025/06/20 02:13:01 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	count_files(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens != NULL)
	{
		if (tokens->next != NULL && (tokens->type == TOKEN_REDIR_IN
				|| tokens->type == TOKEN_REDIR_OUT
				|| tokens->type == TOKEN_REDIR_APPEND)
			&& tokens->next->type == TOKEN_WORD)
			count++;
		tokens = tokens->next;
	}
	return (count);
}
