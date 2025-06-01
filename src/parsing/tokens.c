/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:43:35 by ssallami          #+#    #+#             */
/*   Updated: 2025/06/01 18:48:15 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static t_token *join_token_word(t_token *tokens)
{
	t_token *new_tkn;
	t_token *tmp;
	char *joined;

	new_tkn = NULL;
	while (tokens != NULL)
	{
		if (!(joined = ft_strdup(tokens->value)))
			return (NULL);
		while (tokens->next && tokens->has_space == 0 && tokens->next->type == TOKEN_WORD && tokens->type == TOKEN_WORD)
		{
			joined = ft_strjoin(joined, tokens->next->value);
			if (!joined)
				return (NULL);
			tokens = tokens->next;
		}
		tmp = ft_lstnew_token_add_mode(joined, tokens->type);
		if (!tmp)
			return (NULL);
		ft_lstadd_back(&new_tkn, tmp);
		tokens = tokens->next;
	}
	return (new_tkn);
}

static int quote_check(t_token *lexer)
{
	while (lexer != NULL)
	{
		if (ft_strcmp(lexer->value, "\"") == 0 || ft_strcmp(lexer->value, "'") == 0)
			return (1);
		lexer = lexer->next;
	}
	return (0);
}

static int pipes_check(t_token *token)
{
	if (token && ft_strcmp(token->value, "|") == 0 && token->type != TOKEN_WORD)
		return (1);
	while (token != NULL)
	{
		if (token->next != NULL && ft_strcmp(token->value, "|") == 0 && ft_strcmp(token->next->value, "|") == 0 && token->type != TOKEN_WORD && token->next->type != TOKEN_WORD)
			return (1);
		if (ft_strcmp(token->value, "|") == 0 && token->type != TOKEN_WORD && token->next == NULL)
			return (1);
		token = token->next;
	}
	return (0);
}

static int check_word_after_operator(t_token *tokens)
{
	while (tokens != NULL)
	{
		if ((tokens->type == TOKEN_REDIR_OUT || tokens->type == TOKEN_REDIR_IN || tokens->type == TOKEN_REDIR_APPEND || tokens->type == TOKEN_HEREDOC) && (tokens->next == NULL || tokens->next->type != TOKEN_WORD))
			return (1);
		tokens = tokens->next;
	}
	return (0);
}

static char *string_value(char *s, t_shellvar *vars)
{
	char *result = malloc(1);

	size_t i = 0, j = 0;

	while (s[i])
	{
		if(s[i] == '$' && ft_isdigit(s[i + 1]))
			i +=2;
		else if (s[i] == '$'  &&  (((s[i + 1] == '"' || s[i + 1] == '\'') && ft_isalpha(s[i + 2])) || ft_isalpha(s[i + 1]) || s[i + 1] == '?') )
		{
			i++;
			char *varname = malloc(1);
			if (!varname)
				return NULL;
			int k = 0;

			while (s[i] && (ft_isalnum(s[i]) || s[i] == '_'))
			{
				varname = realloc(varname, k + 2);
				if (!varname)
					return NULL;
				varname[k++] = s[i++];
			}
			varname[k] = '\0';
			// printf("%s\n",varname);


			char *value = getvar(varname, vars);
			if (!value)
				value = ft_strdup("");
			size_t vlen = strlen(value);

			result = realloc(result, j + vlen + 1);
			if (!result)
				return NULL;
			strcpy(&result[j], value);
			j += vlen;
			free(varname);
			if (!getvar(varname, vars))
				free(value);
		}
		else
		{
			result = realloc(result, j + 2);
			if (!result)
				return NULL;
			result[j++] = s[i++];
		}
	}

	result[j] = '\0';
	return result;
}

t_token *tokens(char *input, t_shellvar *vars)
{
	t_token *lexer;
	// t_token	*tokens;
	t_token *handle_tokens;

	// t_token *tmp;
	
    input =	string_value(input, vars);
	lexer = ft_split_lexer(input);
	// tokens = typ_token(lexer);

	if (quote_check(lexer))
	{
		printf("minishell: no equivalent for singel quote (') or double quote (\")\n");
		return (0);
	}
	// print
	// tmp = lexer;
	// while (tmp != NULL)
	// {
	// 	printf("[ %3s ]  -- has space: %3d -- type: %3d\n",
	// 		   tmp->value, tmp->has_space, tmp->type);
	// 	tmp = tmp->next;
	// }
	// printf("NULL\n");
	handle_tokens = join_token_word(lexer);
	if (pipes_check(handle_tokens))
	{
		printf("minishell: syntax error near unexpected token  '|'\n");
		return (0);
	}

	if (check_word_after_operator(handle_tokens))
	{
		printf("minishell: syntax error near unexpected token  '>' or '<' or '>>' or '<<'\n");
		return (0);
	}
	// print
	// tmp = handle_tokens;
	// while (tmp != NULL)
	// {
	// 	printf("[ %3s ]  -- has space: %3d -- type: %3d\n",
	// 		tmp->value, tmp->has_space,
	// 		tmp->type);
	// 	tmp = tmp->next;
	// }
	// printf("NULL\n");
	return (handle_tokens);
}
