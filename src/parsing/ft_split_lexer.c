/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_lexer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:56:24 by ssallami          #+#    #+#             */
/*   Updated: 2025/06/14 08:14:39 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int	is_quote_pair(char *str, int i, int j)
{
	return ((str[i] == '"' && str[j - 1] == '"')
		|| (str[i] == '\'' && str[j - 1] == '\''));
}

static int	is_unclosed_quote(char *str, int i, int j)
{
	return (i == j + 1 && (str[j] == '"' || str[j] == '\''));
}

static int	add_token_if_valid(char *str, t_token **head, int i, int j)
{
	int		isword;
	char	*word;

	isword = is_quote_pair(str, i, j);
	if (i > j)
		word = ft_substr(str, j, i - j);
	else
		word = ft_strdup("");
	if (is_unclosed_quote(str, i, j))
	{
		free(word);
		printf("minishell: no equivalent for quote (') or (\")\n");
		return (false);
	}
	if (i == j && isword)
		ft_lstadd_back(head, ft_lstnew_token_add_type("", isword));
	else if (word)
	{
		ft_lstadd_back(head, ft_lstnew_token_add_type(word, isword));
		free(word);
	}
	if (*head)
		ft_lstlast(*head)->has_space = (str[i] == ' ');
	return (true);
}

t_token	*ft_split_lexer(char *str, t_shellvar *vars)
{
	int		i;
	int		j;
	t_token	*head;

	i = 0;
	j = 0;
	head = NULL;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		j = i;
		len_word(str, &i);
		if (!add_token_if_valid(str, &head, i, j))
		{
			free(str);
			free_tokens(head);
			updatevar("?", "258", vars, false);
			return (NULL);
		}
	}
	return (head);
}
