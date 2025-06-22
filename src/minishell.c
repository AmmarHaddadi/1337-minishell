/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 11:54:08 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/06/20 02:41:47 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool		g_ctrlc = false;


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
				case in:
					printf(BLUE "<\n" RESET);
					break ;
				case heredoc:
					printf(BLUE "<<\n" RESET);
					break ;
				case heredoc_expand:
					printf(BLUE "<<<\n" RESET);
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

static bool	conti(char *input, t_command **cmd, t_shellvar *vars)
{
	if (all_whitespace(input))
	{
		free(input);
		return (true);
	}
	if (g_ctrlc == true)
	{
		g_ctrlc = false;
		free(input);
		return (true);
	}
	add_history(input);
	*cmd = split_commands_tokens(input, vars);
	return (false);
}

static void	wrap(t_shellvar *vars, char *code, char *input, t_command *cmd)
{
	updatevar("?", code, vars, 0);
	free(code);
	free(input);
	freecmd(cmd);
}

static void	end(int e, t_shellvar *vars)
{
	freeenv(vars);
	exit(e % 256);
}

int	main(int ac, char **av, char **env)
{
	char		*input;
	t_command	*cmd;
	t_shellvar	*vars;
	int			xit;

	xit = false;
	(void)ac;
	(void)av;
	signal(SIGQUIT, handle_ctrlback);
	signal(SIGINT, handle_ctrlc);
	vars = envtoll(env);
	while (xit == false)
	{
		input = readline("minishell$ ");
		if (!input)
			break ;
		if (conti(input, &cmd, vars) || !cmd)
			continue ;
		print_command_list(cmd);
		// BREAK POINT TYT
		wrap(vars, ft_itoa(maestro(cmd, vars, &xit)), input, cmd);
	}
	end(ft_atoi(getvar("?", vars)), vars);
}
