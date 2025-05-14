/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_lexer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:56:24 by ssallami          #+#    #+#             */
/*   Updated: 2025/05/14 18:39:14 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

// static char	*ft_strncpy(char *s1, char *s2, int n)
// {
// 	int	i;

// 	i = 0;
// 	while (s2 && i < n)
// 	{
// 		s1[i] = s2[i];
// 		i++;
// 	}
// 	s1[i] = '\0';
// 	return (s1);
// }

static void	len_word(char *str, int *i, int *j)
{
	char	quote;
	int		k;

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
			k = *i;
			while (str[*i] && str[*i] != quote)
				(*i)++;
			if (str[*i] != quote)
				*i = k;
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
		len_word(str, &i, &j);
		if (i >= j)
		{
			word = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(word, &str[j], i - j);

			// check no value insinde in singel quote or double quote ( '' | "" )
			if (i == j && str[i] == '"' && str[j - 1] == '"')
				ft_lstadd_back(&head, ft_lstnew("\"\""));
			else if (i == j && str[i] == '\'' && str[j - 1] == '\'')
				ft_lstadd_back(&head, ft_lstnew("''"));
			else
			{
				// check is no equivalent for singel quote or double quote ( '' | "" )
				if (i == j && str[i - 1] == '"')
					ft_lstadd_back(&head, ft_lstnew("\""));
				else if (i == j && str[i - 1] == '\'')
					ft_lstadd_back(&head, ft_lstnew("'"));
				else if (i != j)
					ft_lstadd_back(&head, ft_lstnew(word));
			}
			// skip " or ' if it was lsat word " or '
			if ((str[i] == '"' && str[j - 1] == '"') || (str[i] == '\'' && str[j
					- 1] == '\''))
				i++;
			if (str[i] && str[i] == ' ')
			{
				last = ft_lstlast2(head);
				last->has_space = 1;
			}
			else
			{
				last = ft_lstlast2(head);
				last->has_space = 0;
			}
		}
	}
	return (head);
}
