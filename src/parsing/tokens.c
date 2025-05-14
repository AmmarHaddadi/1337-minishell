/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:43:35 by ssallami          #+#    #+#             */
/*   Updated: 2025/05/14 18:47:11 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
#include "parsing.h"

static t_token	*typ_token(t_token *lexer)
{
	t_token	*head;

	head = lexer;
	while (lexer != NULL)
	{
		if (ft_strcmp(lexer->value, ">") == 0)
			lexer->type = TOKEN_REDIR_OUT;
		else if (ft_strcmp(lexer->value, "<") == 0)
			lexer->type = TOKEN_REDIR_IN;
		else if (ft_strcmp(lexer->value, ">>") == 0)
			lexer->type = TOKEN_REDIR_APPEND;
		else if (ft_strcmp(lexer->value, "<<") == 0)
			lexer->type = TOKEN_HEREDOC;
		else if (ft_strcmp(lexer->value, "|") == 0)
			lexer->type = TOKEN_PIPE;
		else
			lexer->type = TOKEN_WORD;
		lexer = lexer->next;
	}
	return (head);
}

static t_token	*join_token_word(t_token *tokens)
{
	t_token	*new_tkn;
	t_token	*tmp;
	char	*joined;

	new_tkn = NULL;
	while (tokens != NULL)
	{
		joined = ft_strdup(tokens->value);
		if (!joined)
			return (NULL);
		while (tokens->next && tokens->has_space == 0
			&& tokens->next->type == TOKEN_WORD && tokens->type == TOKEN_WORD)
		{
			joined = ft_strjoin(joined, tokens->next->value);
			if (!joined)
				return (NULL);
			tokens = tokens->next;
		}
		tmp = ft_lstnew(joined);
		if (!tmp)
			return (NULL);
		tmp->type = TOKEN_WORD;
		ft_lstadd_back(&new_tkn, tmp);
		tokens = tokens->next;
	}
	return (new_tkn);
}

static int	quote_check(t_token *lexer)
{
	while (lexer != NULL)
	{
		if (ft_strcmp(lexer->value, "\"") == 0 || ft_strcmp(lexer->value,
				"'") == 0)
			return (1);
		lexer = lexer->next;
	}
	return (0);
}

t_token	*tokens(char *input)
{
	t_token	*lexer;
	t_token	*tokens;
	t_token	*handle_tokens;
	t_token	*tmp;

	lexer = ft_split_lexer(input);
	tokens = typ_token(lexer);
	if (quote_check(tokens))
	{
		printf("minishell: no equivalent for singel quote (') or double quote (\")\n");
		return (0);
	}
	tmp = tokens;
	while (tmp != NULL)
	{
		printf("[ %3s ]  -- has space: %3d -- type: %3d\n", tmp->value,
			tmp->has_space, tmp->type);
		tmp = tmp->next;
	}
	printf("NULL\n");
	handle_tokens = join_token_word(tokens);
	while (handle_tokens != NULL)
	{
		printf("[ %3s ]  -- has space: %3d -- type: %3d\n",
			handle_tokens->value, handle_tokens->has_space,
			handle_tokens->type);
		handle_tokens = handle_tokens->next;
	}
	printf("NULL\n");
	return (tokens);
}
