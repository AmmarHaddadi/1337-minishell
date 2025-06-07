#include "main.h"


int main(int ac, char **av, char **env)
{
	char *input;
	t_command *cmd;

	cmd = NULL;
	(void)ac;
	(void)av;

	t_shellvar *vars = envtoll(env);

	while (1)
	{
		input = readline("minishell$ ");

		// history
		if (!input)
			break;
		if (check_space_newline(input))
			continue;
		add_history(input);

		// exec
		cmd = split_commands_tokens(input, vars);

		free(input);
	}
	
	// freecmd(cmd);

	return (0);
}
