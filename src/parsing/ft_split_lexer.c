/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_lexer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:56:24 by ssallami          #+#    #+#             */
/*   Updated: 2025/06/08 22:22:58 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static void	len_word(char *str, int *i)
{
	char	quote;
	int		k;

	if (str[*i] == '>' || str[*i] == '<' || str[*i] == '|' || str[*i] == '"'
		|| str[*i] == '\'' || str[*i] == '=')
	{
		if (((str[*i + 1] == '>' && str[*i] == '>') || (str[*i + 1] == '<'
					&& str[*i] == '<')) && str[*i] != '|')
			*i += 2;
		else if (str[*i] == '"' || str[*i] == '\'')
		{
			quote = str[*i];
			(*i)++;
			// (*j)++;
			k = *i;
			while (str[*i] && str[*i] != quote)
				(*i)++;
			if (str[*i] != quote)
			{
				*i = k;
				return ;
			}
			(*i)++;
		}
		else
			(*i)++;
	}
	else
	{
		while (str[*i] && str[*i] != ' ' && str[*i] != '\t' && str[*i] != '>'
			&& str[*i] != '<' && str[*i] != '|' && str[*i] != '"'
			&& str[*i] != '\'' && str[*i] != '=')
			(*i)++;
	}
}

t_token	*ft_split_lexer(char *str , t_shellvar *vars)
{
	int		i;
	int		j;
	int		isword;
	t_token	*head;
	t_token	*last;
	char	*word;

	head = NULL;
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		j = i;
		len_word(str, &i);
		if (i >= j)
		{
			isword = 0;
			if ((str[i] == '"' && str[j - 1] == '"') || (str[i] == '\'' && str[j
					- 1] == '\''))
				isword = 1;
			word = ft_substr(str, j, i - j);
			if (!word)
				return (NULL);
			// check no value insinde in singel quote or double quote ( '' | "" )
			if ((i == j && str[i] == '"' && str[j - 1] == '"') || (i == j
					&& str[i] == '\'' && str[j - 1] == '\''))
				ft_lstadd_back(&head, ft_lstnew_token_add_type("", isword));
			// check is no equivalent for singel quote or double quote ( '' | "" )
			else if (i == j + 1 && (str[j] == '"' || str[j] == '\''))
			{
				updatevar("?","258", vars, false);
				return (printf("minishell: no equivalent for singel quote (') or double quote (\")\n"),NULL);
			}
			else if (i != j)
				ft_lstadd_back(&head, ft_lstnew_token_add_type(word, isword));
			last = ft_lstlast(head);
			if (str[i] && str[i] == ' ')
				last->has_space = 1;
			else
				last->has_space = 0;
		}
		free(word);
	}
	return (head);
}
