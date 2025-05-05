/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:43:35 by ssallami          #+#    #+#             */
/*   Updated: 2025/05/05 19:30:08 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
#include "parsing.h"
#include <string.h>

static t_token	*typ_token(t_token *lexer)
{
	t_token	*head;

	head = lexer;
	while (lexer != NULL)
	{
		if (strcmp(lexer->value, ">") == 0)
			lexer->type = TOKEN_REDIR_OUT;
		else if (strcmp(lexer->value, "<") == 0)
			lexer->type = TOKEN_REDIR_IN;
		else if (strcmp(lexer->value, ">>") == 0)
			lexer->type = TOKEN_REDIR_APPEND;
		else if (strcmp(lexer->value, "<<") == 0)
			lexer->type = TOKEN_HEREDOC;
		else if (strcmp(lexer->value, "|") == 0)
			lexer->type = TOKEN_PIPE;
		else
			lexer->type = TOKEN_WORD;
		// printf("value = %3s    type = %3d\n",lexer->value,lexer->type);
		lexer = lexer->next;
	}
	return (head);
}

static t_token *join_token(t_token *tokens)
{
	t_token *new_tkn = NULL;
	t_token *tmp;
	char	*joined;

	while (tokens != NULL)
	{
		if (tokens->has_space == 0 && tokens->next && tokens->next->type == TOKEN_WORD && tokens->type == TOKEN_WORD)
		{
			joined = ft_strjoin(tokens->value, tokens->next->value);
			tmp = ft_lstnew(joined);
			if (!tmp)
				return (NULL); 
			tmp->type = TOKEN_WORD; 
			tmp->has_space = 1;
			ft_lstadd_back(&new_tkn, tmp);

			tokens = tokens->next;
		}
		else
		{
			tmp = ft_lstnew(ft_strdup(tokens->value)); 
			if (!tmp)
				return (NULL);
			tmp->type = tokens->type;
			tmp->has_space = 1;
			ft_lstadd_back(&new_tkn, tmp);
		}
		tokens = tokens->next;
	}
	return (new_tkn);
}


t_token	*tokens(char *input)
{
	t_token	*lexer;
	t_token	*tokens;
	t_token	*handle_tokens;
	// t_token	*tmp;

	lexer = ft_split_lexer(input);
	tokens = typ_token(lexer);
	// tmp = tokens;
	// while (tmp != NULL)
	// {
	// 	printf("[ %3s ]  -- has space: %3d -- type: %3d\n", tmp->value,
	// 		tmp->has_space, tmp->type);
	// 	tmp = tmp->next;
	// }
	// printf("NULL\n");
	handle_tokens = join_token(tokens);
	// while (handle_tokens != NULL)
	// {
	// 	printf("[ %3s ]  -- has space: %3d -- type: %3d\n",
	// 		handle_tokens->value, handle_tokens->has_space,
	// 		handle_tokens->type);
	// 	handle_tokens = handle_tokens->next;
	// }
	printf("NULL\n");
	return (tokens);
}
