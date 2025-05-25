#include "main.h"

int main(int ac, char **av, char **env) {
	char *input;
	t_command *cmd;

	cmd = NULL;
	(void)ac;
	(void)av;

	// int exit_code = 0;
	// t_shellvar *vars = envtoll(env);
	// signal(SIGINT, sigint_handler); // Ctrl+C
	while (1) {
		input = readline("minishell$ ");
		// history
		if (check_space_newline(input))
			continue;
		add_history(input);

		// exec
		cmd = split_commands_tokens(input);

		free(input);
	}
	return (0);
}
