#include "main.h"

bool	ctrlc = false;

#ifdef DEBUG
void	l(void)
{
	system("leaks -q minishell");
}
#endif

int	main(int ac, char **av, char **env)
{
	char		*input;
	t_command	*cmd;
	t_shellvar	*vars;
	char		*code;

	int xit = false; // toggle true to exit
	(void)ac;
	(void)av;
	signal(SIGQUIT, handle_ctrlback);
	signal(SIGINT, handle_ctrlc);
	vars = envtoll(env);
	while (xit == false)
	{
		input = readline("minishell$ ");
		if (ctrlc == true)
		{
			ctrlc = false;
			free(input);
			continue ;
		}
		// EOF aka ctrl-D
		if (!input)
			break ;
		// skip empty input
		if (all_whitespace(input))
		{
			free(input);
			continue ;
		}
		add_history(input);
		cmd = split_commands_tokens(input, vars);
		if (!cmd)
			continue ;
		code = ft_itoa(maestro(cmd, vars, &xit));
		updatevar("?", code, vars, 0);
		free(code);
		free(input);
		freecmd(cmd);

		#ifdef DEBUG
			l();
		#endif
	}
	#ifdef DEBUG
		atexit(l);
	#endif

	xit = ft_atoi(getvar("?", vars));
	// atexit(l);
	freeenv(vars);
	exit(xit % 256);
}
