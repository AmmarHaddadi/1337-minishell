#include "main.h"


#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"


static void	print_command_list(t_command *cmd)
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


// void	l(void)
// {
// 	system("leaks -q minishell");
// }

int main(int ac, char **av, char **env) {
	char *input;
	t_command *cmd;

	cmd = NULL;
	(void)ac;
	(void)av;
	// (void)env;

	// int exit_code = 0;
	t_shellvar *vars = envtoll(env);
	// signal(SIGINT, sigint_handler); // Ctrl+C
	while (1) {
		input = readline("minishell$ ");
		// history
		// if (!input)
		// 	break ;
		if (check_space_newline(input))
			continue;
		add_history(input);

		// exec
		cmd = split_commands_tokens(input , vars);

		print_command_list(cmd);

		free(input);
	}
	// atexit(l);
	return (0);
}
