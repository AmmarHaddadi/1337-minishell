#include "main.h"

bool ctrlc = false;

int main(int ac, char **av, char **env) {
	int xit = false; // toggle true to exit
	char *input;
	t_command *cmd;

	(void)ac;
	(void)av;
	signal(SIGQUIT, handle_ctrlback);
	signal(SIGINT, handle_ctrlc);
	
	t_shellvar *vars = envtoll(env);

	while (xit == false) {
		input = readline("minishell$ ");
		if (ctrlc == true) {
			ctrlc = false;
			free(input);
			continue;
		}
		// EOF aka ctrl-D
		if (!input)
			break;
		// skip empty input
		if (all_whitespace(input)) {
			free(input);
			continue;
		}
		add_history(input);
		cmd = split_commands_tokens(input, vars);
		if (!cmd)
			continue;
		char *code = ft_itoa(maestro(cmd, vars, &xit));
		updatevar("?", code, vars, 0);
		free(code);
		free(input);
		freecmd(cmd);
	}
	xit = ft_atoi(getvar("?", vars));
	freeenv(vars);
	exit(xit % 256);
}
