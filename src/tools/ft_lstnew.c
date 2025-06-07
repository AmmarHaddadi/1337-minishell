/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:23:47 by ssallami          #+#    #+#             */
/*   Updated: 2025/06/07 16:17:58 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_token	*ft_lstnew_token_add_type(void *content , int isword)
{
	t_token	*node;

	node = (t_token *)malloc(sizeof(t_token));
	if (!node)
		return (NULL);
	node->value = ft_strdup(content);

	if (ft_strcmp(content, ">") == 0 && !isword)
			node->type = TOKEN_REDIR_OUT;
		else if (ft_strcmp(content, "<") == 0 && !isword)
			node->type = TOKEN_REDIR_IN;
		else if (ft_strcmp(content, ">>") == 0 && !isword)
			node->type = TOKEN_REDIR_APPEND;
		else if (ft_strcmp(content, "<<") == 0 && !isword)
			node->type = TOKEN_HEREDOC;
		else if (ft_strcmp(content, "|") == 0 && !isword)
			node->type = TOKEN_PIPE;
		else
			node->type = TOKEN_WORD;
	node->next = NULL;
	return (node);
}

t_token	*ft_lstnew_token_add_mode(void *file, int mode)
{
	t_token	*node;

	node = (t_token *)malloc(sizeof(t_token));
	if (!node)
		return (NULL);
	node->value = ft_strdup(file);
	node->type = mode;
	node->next = NULL;
	return (node);
}

t_redir	*ft_lstnew_redir(void *file, int mode)
{
	t_redir	*node;

	node = (t_redir *)malloc(sizeof(t_redir));
	if (!node)
		return (NULL);
	node->filename = ft_strdup(file);
	node->red_mode = mode;
	node->next = NULL;
	return (node);
}
