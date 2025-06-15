/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:43:35 by ssallami          #+#    #+#             */
/*   Updated: 2025/06/14 09:53:32 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int	pipes_check(t_token *token)
{
	if (token && ft_strcmp(token->value, "|") == 0 && token->type != TOKEN_WORD)
		return (1);
	while (token != NULL)
	{
		if (token->next != NULL && ft_strcmp(token->value, "|") == 0
			&& ft_strcmp(token->next->value, "|") == 0
			&& token->type != TOKEN_WORD && token->next->type != TOKEN_WORD)
			return (1);
		if (ft_strcmp(token->value, "|") == 0 && token->type != TOKEN_WORD
			&& token->next == NULL)
			return (1);
		token = token->next;
	}
	return (0);
}

static int	check_word_after_operator(t_token *tokens)
{
	while (tokens != NULL)
	{
		if ((tokens->type == TOKEN_REDIR_OUT || tokens->type == TOKEN_REDIR_IN
				|| tokens->type == TOKEN_REDIR_APPEND
				|| tokens->type == TOKEN_HEREDOC) && (tokens->next == NULL
				|| tokens->next->type != TOKEN_WORD))
			return (1);
		tokens = tokens->next;
	}
	return (0);
}

static void	expand_tokens(t_token *tks, t_shellvar *vars)
{
	char	*tmp;

	while (tks)
	{
		tmp = tks->value;
		tks->value = replace(tmp, vars);
		free(tmp);
		tks = tks->next;
	}
}

static t_token	*syntax_check(t_token *tks, char *input, t_shellvar *vars)
{
	if (pipes_check(tks))
	{
		updatevar("?", "258", vars, false);
		printf("minishell: syntax error near unexpected token  '|'\n");
		free_tokens(tks);
		free(input);
		return (NULL);
	}
	if (check_word_after_operator(tks))
	{
		updatevar("?", "258", vars, false);
		printf("minishell: syntax error '>' '<' '>>' '<<'\n");
		free_tokens(tks);
		free(input);
		return (NULL);
	}
	return (tks);
}

t_token	*tokens(char *input, t_shellvar *vars)
{
	t_token	*lexer;
	t_token	*final;

	lexer = ft_split_lexer(input, vars);
	final = join_token_word(lexer);
	expand_tokens(final, vars);
	free_tokens(lexer);
	return (syntax_check(final, input, vars));
}
