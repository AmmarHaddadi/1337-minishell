/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 23:07:44 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/06/09 23:07:44 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

// 0 -> no
// 1 -> bltn
// 2 -> execute in-shell
static int	isbltn(t_command *cmd)
{
	if (cmd->args == NULL || cmd->args[0] == NULL)
		return (0);
	if (!my_strcmp("echo", cmd->args[0]))
		return (1);
	else if (!my_strcmp("cd", cmd->args[0]))
		return (2);
	else if (!my_strcmp("pwd", cmd->args[0]))
		return (2);
	else if (!my_strcmp("export", cmd->args[0]))
		return (2);
	else if (!my_strcmp("unset", cmd->args[0]))
		return (2);
	else if (!my_strcmp("env", cmd->args[0]))
		return (1);
	else if (!my_strcmp("exit", cmd->args[0]))
		return (1);
	return (0);
}

int	execbltn(t_command *cmd, t_shellvar *vars)
{
	if (!my_strcmp("echo", cmd->args[0]))
		return (echo(cmd));
	else if (!my_strcmp("cd", cmd->args[0]))
		return (cd(cmd, getvar("HOME", vars)));
	else if (!my_strcmp("pwd", cmd->args[0]))
		return (pwd());
	else if (!my_strcmp("export", cmd->args[0]))
		return (export(vars, cmd));
	else if (!my_strcmp("unset", cmd->args[0]))
		return (unset(cmd, &vars));
	else if (!my_strcmp("env", cmd->args[0]))
		return (env(vars));
	else if (!my_strcmp("exit", cmd->args[0]))
		return (builtin_exit(cmd));
	return (0);
}

// NOTE if there is a redir, write to it not the pipe
// NOTE this is it's own fork, so exit, not return
// QUESTION for norme, can I return(f1(), exit(code), 1) ??
// technically I need to free vars and cmd too...
int	bin(t_command *cmd, t_shellvar *vars)
{
	char	*path;
	char	**env;

	if (!cmd->args || !cmd->args[0])
	{
		updatevar("?", "258", vars, false);
		exit(258);
	}
	if (!setupfd(cmd->redirections))
	{
		ft_putstr_fd("can't setup fd\n", STDERR_FILENO);
		exit(1);
	}
	if (isbltn(cmd))
		exit(execbltn(cmd, vars));
	path = getvalidpath(cmd, getvar("PATH", vars));
	if (!path)
		return (ft_putstr_fd("bin not found\n", STDERR_FILENO), exit(127), 11);
	env = varstomatrix(vars);
	if (!env)
		return (ft_putstr_fd("err env\n", STDERR_FILENO), free(path), exit(127),
			11);
	execve(path, cmd->args, env);
	return (perror("execution failed"), freematrix(env), free(path), exit(126),
		1337);
}

int	maestro(t_command *cmd, t_shellvar *vars, int *xt)
{
	int					i;
	struct s_maestro	ms;

	ms.clen = cmdlen(cmd);
	set_xt(cmd, xt);
	if (isbltn(cmd) == 2 && ms.clen == 1)
		return (execbltn(cmd, vars));
	ms.pids = malloc(ms.clen * sizeof(pid_t));
	ms.pipes = setuppipes(ms.clen - 1);
	if (!ms.pids || !ms.pipes)
		return (perror("insufficent memory"), free(ms.pids), 1);
	i = 0;
	while (i < ms.clen)
	{
		if (dofork(ms, i, cmd, vars))
			return (1);
		cmd = cmd->next;
		i++;
	}
	fcp(ms.pipes, ms.clen - 1);
	return (free(ms.pids), getcode(ms.pids, ms.clen));
}
