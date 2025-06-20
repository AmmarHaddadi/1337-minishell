/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:43:35 by ssallami          #+#    #+#             */
/*   Updated: 2025/06/20 02:40:46 by ssallami         ###   ########.fr       */
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
				|| (tokens->next->type != TOKEN_WORD
					&& tokens->next->type != TOKEN_WORD_EXPAND_HEREDOC)))
			return (1);
		tokens = tokens->next;
	}
	return (0);
}

char	*remove_char_malloc(const char *str)
{
	int		i;
	int		j;
	char	*new_str;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	while (str[len])
		len++;
	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		if (str[i] != '\'' && str[i] != '"')
			new_str[j++] = str[i];
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}

static void	expand_tokens(t_token *tks, t_shellvar *vars)
{
	char	*tmp;
	t_token	*get_check_heredoc;

	while (tks)
	{
		tmp = tks->value;
		if (get_check_heredoc->type != TOKEN_HEREDOC)
			tks->value = replace(tmp, vars);
		else
			tks->value = remove_char_malloc(tmp);
		free(tmp);
		get_check_heredoc = tks;
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
