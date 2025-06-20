/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_sgl_dbl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:46:04 by ssallami          #+#    #+#             */
/*   Updated: 2025/06/20 20:47:48 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

char	*skip_sgl_dbl(const char *str)
{
	int		i;
	int		j;
	char	*new_str;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	while (str[len])
		len++;
	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		if (str[i] != '\'' && str[i] != '"')
			new_str[j++] = str[i];
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}
