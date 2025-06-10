/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:39:45 by ssallami          #+#    #+#             */
/*   Updated: 2025/06/09 20:39:53 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	free_tokens(t_token *tks)
{
	t_token	*tmp;

	while (tks)
	{
		tmp = tks->next;
		if (tks->value)
			free(tks->value);
		free(tks);
		tks = tmp;
	}
}
