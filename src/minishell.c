/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:32:36 by ssallami          #+#    #+#             */
/*   Updated: 2025/05/13 21:33:14 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	sigint_handler(int signum)
{
	(void)signum;
	printf("\nexit\n");
	exit(0);
}

int	main(int ac, char **av, char **env)
{
	char		*input;
	t_token		*tks;
	// t_command	*cmd;

	(void)ac;
	(void)av;
	(void)env;
	signal(SIGINT, sigint_handler); // Ctrl+C
	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
		{
			printf("exit\n");
			break ;
		}
		// lexer → parser → execution
		// lexer
		tks = tokens(input);
		// cmd = push_struct(tks);
		(void)tks;
		// t_cmd *cmds = parser(tks);
		// execute_commands(cmds);
		free(input);
	}
	return (0);
}
