/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:32:36 by ssallami          #+#    #+#             */
/*   Updated: 2025/05/16 15:28:08 by ssallami         ###   ########.fr       */
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

void	print_command(t_command *cmd)
{
	int		i;
	t_redir	*redir;

	i = 0;
	if (!cmd)
	{
		printf(RED "Command is NULL.\n" RESET);
		return;
	}

	// طباعة الأرجومنتات
	printf(YELLOW "Arguments:\n" RESET);
	if (cmd->args)
	{
		while (cmd->args[i] != NULL)
		{
			printf(GREEN "  - Arg[%d]: %s\n" RESET, i, cmd->args[i]);
			i++;
		}
	}
	else
		printf(RED "  No arguments found.\n" RESET);

	// طباعة إعادة التوجيهات
	printf(YELLOW "Redirections:\n" RESET);
	redir = cmd->redirections;
	if (redir)
	{
		while (redir != NULL)
		{
			printf(GREEN "  - Filename: %s" RESET " | Mode: ", redir->filename);
			switch (redir->red_mode)
			{
				case override:
					printf(BLUE ">\n" RESET);
					break;
				case append:
					printf(BLUE ">>\n" RESET);
					break;
				case red_in:
					printf(BLUE "<\n" RESET);
					break;
				case red_heredoc:
					printf(BLUE "<<\n" RESET);
					break;
				default:
					printf(RED "no\n" RESET);
					break;
			}
			redir = redir->next;
		}
	}
	else
		printf(RED "  No redirections found.\n" RESET);
}

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
		// طباعة الأرجومنتات
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
		// طباعة إعادة التوجيهات
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
		// التحقق من الأمر التالي
		cmd = cmd->next;
		cmd_count++;
	}
}

static int	count_pipe(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens != NULL)
	{
		if (tokens->type == TOKEN_PIPE)
			count++;
		tokens = tokens->next;
	}
	return (count);
}
t_token	*ft_lstnew_token(void *file, int mode)
{
	t_token	*node;

	node = (t_token *)malloc(sizeof(t_token));
	if (!node)
		return (NULL);
	node->value = ft_strdup(file);
	node->type = mode;
	node->next = NULL;
	return (node);
}

static t_token	*split_commands(t_token *tokens)
{
	t_token	*new_token;

	new_token = NULL;
	while (tokens != NULL && tokens->type != TOKEN_PIPE)
	{
		ft_lstadd_back(&new_token, ft_lstnew_token(tokens->value,
				tokens->type));
		tokens = tokens->next;
	}
	return (new_token);
}
static t_token	*search_mode(t_token *tokens)
{
	if (!tokens)
		return (NULL);
	while (tokens != NULL)
	{
		if (tokens->next != NULL && tokens->type == TOKEN_PIPE)
			break ;
		tokens = tokens->next;
	}
	return (tokens);
}

void	ft_lstadd_back_cmd(t_command **lst, t_command *new)
{
	t_command	*prt;

	prt = *lst;
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (prt->next != NULL)
		prt = prt->next;
	prt->next = new;
}
int	main(int ac, char **av, char **env)
{
	char		*input;
	t_token		*tks;
	t_token		*pipe;
	t_token		*split_tokens;
	t_command	*cmd;
	t_command	*new_cmd;
	int			countPipe;

	cmd = NULL;
	new_cmd = NULL;
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
		countPipe = count_pipe(tks);
		printf("%d))\n", countPipe);
		// split_commands()
		while (countPipe >= 0 && tks != NULL)
		{
			new_cmd = NULL;
			// 1. split cmd
			split_tokens = split_commands(tks);
			// 2. push cmd
			new_cmd = push_struct(split_tokens);
			// if (new_cmd)
			// 	print_command(new_cmd);
			// else
			// 	printf("New command is NULL.\n");
			ft_lstadd_back_cmd(&cmd, new_cmd);
			// 3. next pipe
			pipe = search_mode(tks);
			if (!pipe)
				break ;
			tks = pipe->next;
			countPipe--;
		}
		printf("============\n");
		printf("============\n");
		print_command_list(cmd);
		cmd = NULL;
		printf("============\n");
		printf("============\n");
		(void)cmd;
		// t_cmd *cmds = parser(tks);
		// execute_commands(cmds);
		free(input);
	}
	return (0);
}
