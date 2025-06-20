/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_token_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 07:44:07 by ssallami          #+#    #+#             */
/*   Updated: 2025/06/20 02:45:23 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static char	*merge_words(t_token **tks, int *vld)
{
	char	*joined;
	char	*tmp;

	if ((*tks)->type == TOKEN_WORD_EXPAND_HEREDOC)
		*vld = 1;
	joined = ft_strdup((*tks)->value);
	if (!joined)
		return (NULL);
	while ((*tks)->next && !(*tks)->has_space && ((*tks)->type == TOKEN_WORD
			|| (*tks)->type == TOKEN_WORD_EXPAND_HEREDOC)
		&& ((*tks)->next->type == TOKEN_WORD
			|| (*tks)->next->type == TOKEN_WORD_EXPAND_HEREDOC))
	{
		if ((*tks)->type == TOKEN_WORD_EXPAND_HEREDOC)
			*vld = 1;
		tmp = ft_strjoin(joined, (*tks)->next->value);
		if (!tmp)
			return (free(joined), NULL);
		free(joined);
		joined = tmp;
		(*tks) = (*tks)->next;
	}
	return (joined);
}

t_token	*join_token_word(t_token *tokens)
{
	t_token	*new;
	t_token	*node;
	char	*joined;
	int		vld;

	new = NULL;
	while (tokens)
	{
		vld = 0;
		joined = merge_words(&tokens, &vld);
		if (!joined)
			return (NULL);
		if (vld == 1)
			tokens->type = TOKEN_WORD_EXPAND_HEREDOC;
		node = ft_lstnew_token_add_mode(joined, tokens->type);
		free(joined);
		if (!node)
			return (NULL);
		ft_lstadd_back(&new, node);
		tokens = tokens->next;
	}
	return (new);
}
