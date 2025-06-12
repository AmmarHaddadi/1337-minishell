/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env-helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 21:39:42 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/06/07 21:39:42 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

t_shellvar	*envtoll(char **env)
{
	t_shellvar	*head;
	t_shellvar	*curr;
	char		**s;
	int			i;

	if (!env)
		return (NULL);
	head = malloc(sizeof(t_shellvar));
	curr = head;
	i = 0;
	while (env[i])
	{
		s = ft_split(env[i], '=');
		curr->key = ft_strdup(s[0]);
		curr->value = ft_strdup(s[1]);
		curr->exported = true;
		if (env[++i] == NULL)
			curr->next = NULL;
		else
			curr->next = malloc(sizeof(t_shellvar));
		curr = curr->next;
		freematrix(s);
	}
	updatevar("?", "0", head, 0);
	return (head);
}

// WARN only free using freeenv();
char	*getvar(char *key, t_shellvar *vars)
{
	if (!key || !*key || !vars)
		return (NULL);
	while (vars != NULL)
	{
		if (!my_strcmp(key, vars->key))
			return (vars->value);
		vars = vars->next;
	}
	return (NULL);
}

void	freeenv(t_shellvar *vars)
{
	t_shellvar	*next;
	t_shellvar	*curr;

	curr = vars;
	while (curr)
	{
		next = curr->next;
		free(curr->key);
		free(curr->value);
		free(curr);
		curr = next;
	}
}
