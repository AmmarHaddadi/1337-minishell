/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:40:14 by ssallami          #+#    #+#             */
/*   Updated: 2025/06/09 21:33:04 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int	count_files(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens != NULL)
	{
		if (tokens->next != NULL && (tokens->type == TOKEN_REDIR_IN
				|| tokens->type == TOKEN_REDIR_OUT
				|| tokens->type == TOKEN_REDIR_APPEND
				|| tokens->type == TOKEN_HEREDOC)
			&& tokens->next->type == TOKEN_WORD)
			count++;
		tokens = tokens->next;
	}
	return (count);
}

static int	count_operator(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens != NULL)
	{
		if (tokens->next != NULL && (tokens->type == TOKEN_REDIR_IN
				|| tokens->type == TOKEN_REDIR_OUT
				|| tokens->type == TOKEN_REDIR_APPEND
				|| tokens->type == TOKEN_HEREDOC || tokens->type == TOKEN_PIPE))
			count++;
		tokens = tokens->next;
	}
	return (count);
}
static t_token	*search_mode(t_token *tokens)
{
	if (!tokens)
		return (NULL);
	while (tokens != NULL)
	{
		if (tokens->next != NULL && (tokens->type == TOKEN_REDIR_IN
				|| tokens->type == TOKEN_REDIR_OUT
				|| tokens->type == TOKEN_REDIR_APPEND
				|| tokens->type == TOKEN_HEREDOC))
			break ;
		tokens = tokens->next;
	}
	return (tokens);
}
static void	fill_redirections(t_token **tokens, t_command *cmd)
{
	t_token	*tkn;

	while ((tkn = search_mode(*tokens)))
	{
		if (tkn->next)
		{
			ft_lstadd_back_redir(&cmd->redirections,
				ft_lstnew_redir(tkn->next->value, tkn->type));
			tkn->type = 10;
			tkn->next->type = 10;
			*tokens = tkn->next->next;
		}
		else
			break ;
	}
}

static char	**extract_args(t_token *head, int count)
{
	char	**args;
	int		i;

	args = malloc(sizeof(char *) * (count + 1));
	i = 0;
	if (!args)
		return (NULL);
	while (head && i < count)
	{
		if (head->type == TOKEN_WORD)
			args[i++] = ft_strdup(head->value);
		head = head->next;
	}
	args[i] = NULL;
	return (args);
}

t_command	*push_struct(t_token *tokens)
{
	t_command	*cmd;
	t_token		*head;
	int			files;
	int			ops;
	int			words;

	cmd = malloc(sizeof(t_command));
	head = tokens;
	files = count_files(tokens);
	ops = count_operator(tokens);
	words = ft_lstsize_token(head) - (files + ops);
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->redirections = NULL;
	cmd->next = NULL;
	fill_redirections(&tokens, cmd);
	cmd->args = extract_args(head, words);
	return (cmd);
}
