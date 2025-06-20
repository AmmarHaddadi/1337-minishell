/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 09:49:31 by ssallami          #+#    #+#             */
/*   Updated: 2025/06/20 02:43:21 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int	count_pipe(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens != NULL)
	{
		if (tokens->type == TOKEN_PIPE)
			count++;
		tokens = tokens->next;
	}
	return (count);
}

static t_token	*split_commands(t_token *tokens)
{
	t_token	*new_token;

	new_token = NULL;
	while (tokens != NULL && tokens->type != TOKEN_PIPE)
	{
		ft_lstadd_back(&new_token, ft_lstnew_token_add_mode(tokens->value,
				tokens->type));
		tokens = tokens->next;
	}
	return (new_token);
}

static t_token	*search_mode(t_token *tokens)
{
	if (!tokens)
		return (NULL);
	while (tokens != NULL)
	{
		if (tokens->next != NULL && tokens->type == TOKEN_PIPE)
			break ;
		tokens = tokens->next;
	}
	return (tokens);
}

static t_command	*create_command(t_token **tks, int *count)
{
	t_command	*cmd;
	t_token		*next;

	next = split_commands(*tks);
	cmd = push_struct(next);
	free_tokens(next);
	*tks = search_mode(*tks);
	if (*tks)
		*tks = (*tks)->next;
	(*count)--;
	return (cmd);
}

t_command	*split_commands_tokens(char *input, t_shellvar *vars)
{
	t_command	*cmds;
	t_token		*tks;
	t_token		*tks_head;
	int			count;

	cmds = NULL;
	tks = tokens(input, vars);
	if (tks == NULL)
		return (NULL);
	tks_head = tks;
	count = count_pipe(tks);
	while (count >= 0 && tks)
		ft_lstadd_back_cmd(&cmds, create_command(&tks, &count));
	prepare_heredocs(cmds, vars);
	free_tokens(tks_head);
	return (cmds);
}
