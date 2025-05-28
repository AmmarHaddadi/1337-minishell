#include "main.h"

int main(int ac, char **av, char **env) {
	char *input;
	t_command *cmd;

	(void)ac;
	(void)av;

	t_shellvar *vars = envtoll(env);
	if (!vars) {
		printf("no env");
		return 1;
	}
	// signal(SIGINT, sigint_handler); // Ctrl+C
	while (1) {
		input = readline("minishell$ ");
		if (check_space_newline(input))
			continue;
		add_history(input);
		cmd = split_commands_tokens(input);
		maestro(cmd, vars);
		free(input);
		freecmd(cmd);
	}
	freeenv(vars);
}
