/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 01:38:13 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/06/12 01:38:13 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

void	handle_ctrlback(int sig)
{
	(void)sig;
}

void	rl_replace_line(const char *s, int a);

// ctrl-c
void	handle_ctrlc(int sig)
{
	extern bool	ctrlc;

	(void)sig;
	ctrlc = true;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
