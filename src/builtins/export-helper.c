/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export-helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 21:39:42 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/06/07 21:39:42 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

static void	swap(t_shellvar *ptr)
{
	char	*tmp_key;
	char	*tmp_val;
	bool	tmp_exp;

	tmp_key = ptr->key;
	tmp_val = ptr->value;
	tmp_exp = ptr->exported;
	ptr->key = ptr->next->key;
	ptr->value = ptr->next->value;
	ptr->exported = ptr->next->exported;
	ptr->next->key = tmp_key;
	ptr->next->value = tmp_val;
	ptr->next->exported = tmp_exp;
}

void	bubble_sort_shellvars(t_shellvar *head)
{
	bool		swapped;
	t_shellvar	*ptr;
	t_shellvar	*last;

	if (!head)
		return ;
	swapped = true;
	last = NULL;
	while (swapped)
	{
		swapped = false;
		ptr = head;
		while (ptr->next != last)
		{
			if (my_strcmp(ptr->key, ptr->next->key) > 0)
			{
				swap(ptr);
				swapped = 1;
			}
			ptr = ptr->next;
		}
		last = ptr;
	}
}
