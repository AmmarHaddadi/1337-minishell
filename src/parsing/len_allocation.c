/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_allocation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:55:24 by ssallami          #+#    #+#             */
/*   Updated: 2025/06/20 01:51:30 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static t_quote	update_quote(char c, t_quote current)
{
	if (c == '\'' && current == none)
		return (single);
	if (c == '\'' && current == single)
		return (none);
	if (c == '\"' && current == none)
		return (dbl);
	if (c == '\"' && current == dbl)
		return (none);
	return (current);
}

static int	vld_dollar_len(char c, t_quote q)
{
	return ((q == none || q == dbl) && (ft_isalpha(c) || c == '_' || c == '?'
			|| !c));
}

void	free_val_key(char *key, char *val)
{
	free(key);
	free(val);
}

static int	handle_dollar_case(char *s, t_quote q, t_shellvar *vars, int *len)
{
	int		j;
	char	*key;
	char	*tmp;
	char	*val;

	if (vld_dollar_len(s[1], q))
	{
		j = 1;
		while (ft_isalnum(s[j]) || s[j] == '_' || s[j] == '?')
			j++;
		key = ft_substr(s, 1, j - 1);
		tmp = getvar(key, vars);
		if (tmp != NULL)
			val = ft_strdup(tmp);
		else
			val = ft_strdup("");
		*len += ft_strlen(val);
		free_val_key(key, val);
		return (j - 1);
	}
	if (q == none && (s[1] == '\'' || s[1] == '"'))
		return (0);
	if (ft_isdigit(s[1]))
		return (1);
	return (0);
}

int	len_allocation(char *input, t_shellvar *vars)
{
	t_quote	quote;
	int		i;
	int		str_len;

	quote = none;
	str_len = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '"' || input[i] == '\'')
			quote = update_quote(input[i], quote);
		else if (input[i] == '$')
			i += handle_dollar_case(input + i, quote, vars, &str_len);
		else
			str_len++;
		i++;
	}
	return (str_len);
}
