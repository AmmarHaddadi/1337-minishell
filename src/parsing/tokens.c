/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:43:35 by ssallami          #+#    #+#             */
/*   Updated: 2025/06/12 16:13:54 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static t_token	*join_token_word(t_token *tokens)
{
	t_token	*new_tkn;
	t_token	*tmp;
	char	*joined;
	char	*tmp_str;

	new_tkn = NULL;
	while (tokens != NULL)
	{
		if (!(joined = ft_strdup(tokens->value)))
			return (NULL);
		while (tokens->next && tokens->has_space == 0
			&& tokens->next->type == TOKEN_WORD && tokens->type == TOKEN_WORD)
		{
			tmp_str = ft_strjoin(joined, tokens->next->value);
			if (!tmp_str)
			{
				free(joined);
				return (NULL);
			}
			free(joined);
			joined = tmp_str;
			tokens = tokens->next;
		}
		tmp = ft_lstnew_token_add_mode(joined, tokens->type);
		free(joined);
		if (!tmp)
			return (NULL);
		ft_lstadd_back(&new_tkn, tmp);
		tokens = tokens->next;
	}
	return (new_tkn);
}

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

t_token	*tokens(char *input, t_shellvar *vars)
{
	t_token	*lexer;
	t_token	*handle_tokens;
	t_token	*tmp;

	lexer = ft_split_lexer(input, vars);
	handle_tokens = join_token_word(lexer);
	tmp = handle_tokens;
	char *tmp_val;
	while (tmp != NULL)
	{
		tmp_val = tmp->value;
		tmp->value = replace(tmp->value, vars);
		free(tmp_val);
		tmp = tmp->next;
	}
	free_tokens(lexer);
	if (pipes_check(handle_tokens))
	{
		free_tokens(handle_tokens);
		free(input);
		updatevar("?", "258", vars, false);
		return (printf("minishell: syntax error near unexpected token  '|'\n"),NULL);
	}
	if (check_word_after_operator(handle_tokens))
	{
		free_tokens(handle_tokens);
		free(input);
		updatevar("?","258", vars, false);
		return (printf("minishell: syntax error near unexpected token  '>' or '<' or '>>' or '<<'\n"),NULL);
	}
	return (handle_tokens);
}
