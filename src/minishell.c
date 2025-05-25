#include "main.h"

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
		// print_command_list(cmd);
		printf("============\n");
		cmd = NULL;
		(void)cmd;
		free(input);
	}
	return (0);
}
