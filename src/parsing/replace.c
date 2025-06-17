/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:34:13 by ssallami          #+#    #+#             */
/*   Updated: 2025/06/17 17:02:26 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int	update_quote_state(char **input, int *p, char c, t_quote *quote)
{
	if (c == '\"')
	{
		if (*quote == none)
			*quote = dbl;
		else if (*quote == dbl)
			*quote = none;
		else
			*input[(*p)++] = '"';
		return (true);
	}
	else if (c == '\'')
	{
		if (*quote == none)
			*quote = single;
		else if (*quote == single)
			*quote = none;
		else
			*input[(*p)++] = '\'';
		return (true);
	}
	return (false);
}

char	*replace(char *input, t_shellvar *vars)
{
	t_quote	quote;
	char	*buffer[2];
	int		tab[2];

	buffer[0] = input;
	tab[0] = 0;
	tab[1] = 0;
	quote = none;
	buffer[1] = malloc(sizeof(char) * (len_allocation(buffer[0], vars) + 1));
	while (buffer[0][tab[0]])
	{
		if (update_quote_state(&buffer[0], &tab[1], buffer[0][tab[0]], &quote))
			tab[1] += 0;
		else if (expand_dollar(buffer, tab, &quote, vars))
			tab[1] += 0;
		else
			buffer[1][tab[1]++] = buffer[0][tab[0]];
		tab[0]++;
	}
	buffer[1][tab[1]] = '\0';
	return (buffer[1]);
}
