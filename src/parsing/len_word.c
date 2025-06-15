/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:34:51 by ssallami          #+#    #+#             */
/*   Updated: 2025/06/09 20:35:20 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int	is_special_char(char c)
{
	return (c == ' ' || c == '\t' || c == '>' || c == '<' || c == '|'
		|| c == '"' || c == '\'' || c == '=');
}

static void	skip_word(char *str, int *i)
{
	while (str[*i] && !is_special_char(str[*i]))
		(*i)++;
}

static void	handle_quotes(char *str, int *i)
{
	char	quote;
	int		start;

	quote = str[*i];
	(*i)++;
	start = *i;
	while (str[*i] && str[*i] != quote)
		(*i)++;
	if (str[*i] != quote)
		*i = start;
	else
		(*i)++;
}

void	len_word(char *str, int *i)
{
	if (((str[*i + 1] == '>' && str[*i] == '>') || (str[*i + 1] == '<'
				&& str[*i] == '<')) && str[*i] != '|')
		*i += 2;
	else if (!is_special_char(str[*i]))
		skip_word(str, i);
	else if (str[*i] == '"' || str[*i] == '\'')
		handle_quotes(str, i);
	else
		(*i)++;
}
