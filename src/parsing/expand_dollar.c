/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:57:00 by ssallami          #+#    #+#             */
/*   Updated: 2025/06/17 17:00:01 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int	vld_dollar(char c)
{
	return (ft_isalpha(c) || ft_isdigit(c) || c == '_' || c == '?');
}

static char	*get_val(char *input, int i, int *skip, t_shellvar *vars)
{
	int		j;
	char	*key;
	char	*tmp;
	char	*val;

	*skip = 0;
	j = i + 1;
	while (vld_dollar(input[j]))
		j++;
	key = ft_substr(input, i + 1, j - i - 1);
	tmp = getvar(key, vars);
	if (tmp != NULL)
		val = ft_strdup(tmp);
	else
		val = ft_strdup("");
	free(key);
	*skip = j - i - 1;
	return (val);
}

int	expand_dollar(char *buffer[2], int tab[2], t_quote *quote, t_shellvar *vars)
{
	int		skip;
	char	*val;
	size_t	k;

	skip = 0;
	if (buffer[0][tab[0]] == '$' && (*quote == none || *quote == dbl)
		&& (ft_isalpha(buffer[0][tab[0] + 1]) || buffer[0][tab[0] + 1] == '?'
			|| buffer[0][tab[0] + 1] == '_' || !buffer[0][tab[0] + 1]))
	{
		val = get_val(buffer[0], tab[0], &skip, vars);
		k = 0;
		while (k < ft_strlen(val))
			buffer[1][tab[1]++] = val[k++];
		free(val);
		tab[0] += skip;
		return (true);
	}
	else if (buffer[0][tab[0]] == '$' && *quote == none && (buffer[0][tab[0]
			+ 1] == '\'' || buffer[0][tab[0] + 1] == '"'))
		return (tab[0] += 0, true);
	else if (buffer[0][tab[0]] == '$' && ft_isdigit(buffer[0][tab[0] + 1]))
		return (tab[0] += 1, true);
	return (false);
}
