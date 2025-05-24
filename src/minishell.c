/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:32:36 by ssallami          #+#    #+#             */
/*   Updated: 2025/05/22 20:45:08 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	sigint_handler(int signum)
{
	(void)signum;
	printf("\nexit\n");
	exit(0);
}

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"


void	print_command_list(t_command *cmd)
{
	int		i;
	t_redir	*redir;
	int		cmd_count;

	cmd_count = 1;
	if (!cmd)
	{
		printf(RED "Command list is NULL.\n" RESET);
		return ;
	}
	while (cmd)
	{
		printf(CYAN "\n=== Command %d ===\n" RESET, cmd_count);
		printf(YELLOW "Arguments:\n" RESET);
		if (cmd->args)
		{
			i = 0;
			while (cmd->args[i] != NULL)
			{
				printf(GREEN "  - Arg[%d]: %s\n" RESET, i, cmd->args[i]);
				i++;
			}
		}
		else
			printf(RED "  No arguments found.\n" RESET);
		printf(YELLOW "Redirections:\n" RESET);
		redir = cmd->redirections;
		if (redir)
		{
			while (redir != NULL)
			{
				printf(GREEN "  - Filename: %s" RESET " | Mode: ",
					redir->filename);
				switch (redir->red_mode)
				{
				case override:
					printf(BLUE ">\n" RESET);
					break ;
				case append:
					printf(BLUE ">>\n" RESET);
					break ;
				case red_in:
					printf(BLUE "<\n" RESET);
					break ;
				case red_heredoc:
					printf(BLUE "<<\n" RESET);
					break ;
				default:
					printf(RED "no\n" RESET);
					break ;
				}
				redir = redir->next;
			}
		}
		else
			printf(RED "  No redirections found.\n" RESET);
		cmd = cmd->next;
		cmd_count++;
	}
}

static int	check_space_newline(char *input)
{
	int	i;
	i = 0;
	while (input[i])
	{
		if (input[i] != ' ' && input[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av, char **env)
{
	char		*input;
	t_token		*tks;
	t_command	*cmd;

	cmd = NULL;
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
		// history
		if(check_space_newline(input))
			continue ;
		add_history(input);
		// lexer
		tks = tokens(input);
		// split_commands()
		cmd = split_commands_tokens(tks);
		
		printf("============\n");
		print_command_list(cmd);
		printf("============\n");
		cmd = NULL;
		(void)cmd;
		free(input);
	}
	return (0);
}
