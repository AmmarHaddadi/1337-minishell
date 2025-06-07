/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:43:35 by ssallami          #+#    #+#             */
/*   Updated: 2025/05/24 16:24:13 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static t_token *typ_token(t_token *lexer) {
	t_token *head;

	head = lexer;
	while (lexer != NULL) {
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

static t_token *join_token_word(t_token *tokens) {
	t_token *new_tkn;
	t_token *tmp;
	char *joined;

	new_tkn = NULL;
	while (tokens != NULL) {
		if (!(joined = ft_strdup(tokens->value)))
			return (NULL);
		while (tokens->next && tokens->has_space == 0 &&
			   tokens->next->type == TOKEN_WORD && tokens->type == TOKEN_WORD) {
			joined = ft_strjoin(joined, tokens->next->value);
			if (!joined)
				return (NULL);
			tokens = tokens->next;
		}
		tmp = ft_lstnew_token(joined);
		if (!tmp)
			return (NULL);
		tmp->type = tokens->type;
		ft_lstadd_back(&new_tkn, tmp);
		tokens = tokens->next;
	}
	return (new_tkn);
}

static int quote_check(t_token *lexer) {
	while (lexer != NULL) {
		if (ft_strcmp(lexer->value, "\"") == 0 ||
			ft_strcmp(lexer->value, "'") == 0)
			return (1);
		lexer = lexer->next;
	}
	return (0);
}

static int pipes_check(t_token *token) {
	if (token && ft_strcmp(token->value, "|") == 0)
		return (1);
	while (token != NULL) {
		if (token->next != NULL && ft_strcmp(token->value, "|") == 0 &&
			ft_strcmp(token->next->value, "|") == 0)
			return (1);
		if (ft_strcmp(token->value, "|") == 0 && token->next == NULL)
			return (1);
		token = token->next;
	}
	return (0);
}

t_token *tokens(char *input) {
	t_token *lexer;
	t_token *tokens;
	t_token *handle_tokens;

	lexer = ft_split_lexer(input);
	tokens = typ_token(lexer);

	if (quote_check(tokens)) {
		printf("minishell: no equivalent for singel quote (') or double quote "
			   "(\")\n");
		return (0);
	}
	#ifdef TOKEN
	// print
	t_token *tmp;
	tmp = tokens;
	while (tmp != NULL) {
		printf("[ %3s ]  -- has space: %3d -- type: %3d\n", tmp->value,
			   tmp->has_space, tmp->type);
		tmp = tmp->next;
	}
	printf("NULL\n");
	#endif
	handle_tokens = join_token_word(tokens);
	if (pipes_check(handle_tokens)) {
		printf("minishell: syntax error near unexpected token  '|'\n");
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
