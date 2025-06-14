/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 11:54:08 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/06/14 11:54:08 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

bool		g_ctrlc = false;

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
		wrap(vars, ft_itoa(maestro(cmd, vars, &xit)), input, cmd);
	}
	end(ft_atoi(getvar("?", vars)), vars);
}
