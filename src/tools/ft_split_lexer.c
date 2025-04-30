/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_lexer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:56:24 by ssallami          #+#    #+#             */
/*   Updated: 2025/04/30 20:56:34 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s2 && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

static int	check_allspace(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

static void	len_word(char *str, int *i, int *j)
{
	char	quote;

	if (str[*i] == '>' || str[*i] == '<' || str[*i] == '|' || str[*i] == '"'
		|| str[*i] == '\'' || str[*i] == '=')
	{
		if (str[*i + 1] == '>' || str[*i + 1] == '<')
			*i += 2;
		else if (str[*i] == '"' || str[*i] == '\'')
		{
			quote = str[*i];
			(*i)++;
			(*j)++;
			while (str[*i] && str[*i] != quote)
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

t_token	*ft_split_lexer(char *str)
{
	int		i;
	int		j;
	t_token	*head;
	char	*word;

	head = NULL;
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		j = i;
		len_word(str, &i, &j);
		if (i > j)
		{
			word = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(word, &str[j], i - j);
			if(  str[i - j + 1] == '"' ||  str[i - j + 1] == '\'')
				i++;
			if (check_allspace(word) != 0)
				ft_lstadd_back(&head, ft_lstnew(word));
		}
	}
	return (head);
}
