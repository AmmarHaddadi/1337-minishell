/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:43:35 by ssallami          #+#    #+#             */
/*   Updated: 2025/04/30 21:05:47 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
#include "parsing.h"

t_token	*tokens(char *input)
{
	t_token	*tokens;

	tokens = ft_split_lexer(input);
    
	// while (tokens != NULL)
	// {
	// 	printf("[ %s ] --> ", tokens->value);
	// 	tokens = tokens->next;
	// }
	// printf("NULL\n");
    
	return (tokens);
}
