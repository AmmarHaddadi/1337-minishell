/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setupfds2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 00:09:05 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/06/10 00:09:05 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

bool	routeout(int *ofd, int outmode, char *redfile)
{
	if (!redfile)
		return (true);
	*ofd = open(redfile, outmode | O_WRONLY, 0644);
	if (*ofd < 0)
		return (perror("Can't open output file"), false);
	if (dup2(*ofd, STDOUT_FILENO) < 0)
		return (perror("Can't forward output to file"), close(*ofd), false);
	return (true);
}
