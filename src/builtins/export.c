/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 21:39:42 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/06/07 21:39:42 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

// export VAR -> export=true
// export VAR=VAL -> export=true and update val || create

static t_shellvar	*mallocvar(char *key, char *val, bool exported)
{
	t_shellvar	*var;

	var = malloc(sizeof(t_shellvar));
	var->key = ft_strdup(key);
	var->value = ft_strdup(val);
	var->exported = exported;
	var->next = NULL;
	return (var);
}

// updates/create shellvar
void	updatevar(char *key, char *val, t_shellvar *vars, bool exported)
{
	t_shellvar	*previous;

	if (!vars)
		return ;
	previous = NULL;
	while (vars != NULL)
	{
		if (!my_strcmp(vars->key, key))
		{
			if (val)
			{
				free(vars->value);
				vars->value = ft_strdup(val);
			}
			vars->exported = exported;
			return ;
		}
		previous = vars;
		vars = vars->next;
	}
	previous->next = mallocvar(key, val, exported);
	return ;
}

static void	printtvars(t_shellvar *vars)
{
	bubble_sort_shellvars(vars);
	while (vars != NULL)
	{
		if (vars->value && vars->exported == true)
			printf("declare -x %s=\"%s\"\n", vars->key, vars->value);
		else if (vars->exported == true)
			printf("declare -x %s\n", vars->key);
		vars = vars->next;
	}
}

int	export(t_shellvar *vars, t_command *command)
{
	char	**e;
	int		i;

	i = 1;
	if (matrixlen(command->args) == 1)
		return (printtvars(vars), 0);
	while (command->args[i])
	{
		e = ft_split(command->args[i], '=');
		if (!ft_isalpha(e[0][0]) && e[0][0] != '_')
		{
			printf("export: '%s': not a valid identifier\n", e[0]);
			return (freematrix(e), 1);
		}
		if (ft_strchr(command->args[i], '=') && e[1])
			updatevar(e[0], e[1], vars, true);
		else if (ft_strchr(command->args[i], '='))
			updatevar(e[0], "", vars, true);
		else
			updatevar(e[0], NULL, vars, true);
		freematrix(e);
		i++;
	}
	return (0);
}
