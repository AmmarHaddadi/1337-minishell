/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 22:49:12 by ssallami          #+#    #+#             */
/*   Updated: 2025/06/16 14:01:00 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	sigint_handler(int signum)
{
	(void)signum;
	printf("\nexit\n");
	exit(0);
}

// check if all is white spaces
bool	all_whitespace(char *input)
{
	int	i;

	if (!*input)
		return (true);
	i = 0;
	while (input[i])
	{
		if (input[i] != ' ' && input[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}
