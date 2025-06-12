/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 21:39:42 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/06/07 21:39:42 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

int	unset(t_command *command, t_shellvar **vars)
{
	char		*key;
	t_shellvar	*current;
	t_shellvar	*prvs;

	key = command->args[1];
	if (!key || !*key || (!ft_isalpha(key[0]) && key[0] != '_'))
		return (ft_putstr_fd("Invalid key", STDERR_FILENO), 1);
	current = *vars;
	prvs = NULL;
	while (current)
	{
		if (!my_strcmp(current->key, key))
		{
			if (prvs)
				prvs->next = current->next;
			else
				*vars = current->next;
			return (free(current->key), free(current->value), free(current), 0);
		}
		prvs = current;
		current = current->next;
	}
	return (1);
}
