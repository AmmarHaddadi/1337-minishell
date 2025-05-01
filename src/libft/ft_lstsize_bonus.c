/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:03:08 by ahaddadi          #+#    #+#             */
/*   Updated: 2024/11/09 13:19:48 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
// 	// Test Case 1: Empty list
// 	t_list *list1 = NULL;
// 	int size1 = ft_lstsize(list1);
// 	printf("Size of list1: %d\n", size1); // Expected output: 0

// 	// Test Case 2: List with one element
// 	t_list *list2 = malloc(sizeof(t_list));
// 	list2->next = NULL;
// 	int size2 = ft_lstsize(list2);
// 	printf("Size of list2: %d\n", size2); // Expected output: 1

// 	// Test Case 3: List with multiple elements
// 	t_list *list3 = malloc(sizeof(t_list));
// 	list3->next = malloc(sizeof(t_list));
// 	list3->next->next = malloc(sizeof(t_list));
// 	list3->next->next->next = NULL;
// 	int size3 = ft_lstsize(list3);
// 	printf("Size of list3: %d\n", size3); // Expected output: 3

// 	return 0;
// }
