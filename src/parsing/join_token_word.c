/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_token_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 07:44:07 by ssallami          #+#    #+#             */
/*   Updated: 2025/06/14 07:45:51 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static char	*merge_words(t_token **tks)
{
	char	*joined;
	char	*tmp;

	joined = ft_strdup((*tks)->value);
	if (!joined)
		return (NULL);
	while ((*tks)->next && !(*tks)->has_space && (*tks)->type == TOKEN_WORD
		&& (*tks)->next->type == TOKEN_WORD)
	{
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

	new = NULL;
	while (tokens)
	{
		joined = merge_words(&tokens);
		if (!joined)
			return (NULL);
		node = ft_lstnew_token_add_mode(joined, tokens->type);
		free(joined);
		if (!node)
			return (NULL);
		ft_lstadd_back(&new, node);
		tokens = tokens->next;
	}
	return (new);
}
