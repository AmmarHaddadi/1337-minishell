/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:39:40 by ahaddadi          #+#    #+#             */
/*   Updated: 2024/11/08 19:17:48 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*space;

	space = malloc(count * size);
	if (!space)
		return (NULL);
	ft_bzero(space, count * size);
	return (space);
}

// NULL tests
// int main()
// {
// 	char *a = ft_calloc(0, 0);
// 	free(a);
// }

// #include <stdlib.h>
// #include <stdio.h>
// #include <assert.h>
// #include <string.h>
// #include "libft.h"

// void test_ft_calloc(size_t count, size_t size)
// {
// 	void *res_ft = ft_calloc(count, size);
// 	void *res_std = calloc(count, size);

// 	// Check if both results are NULL when count or size is 0
// 	if (count == 0 || size == 0) {
// 		assert(res_ft != NULL);
// 		assert(res_std != NULL);
// 	} else {
// 		// Check if both results are not NULL
// 		assert(res_ft != NULL);
// 		assert(res_std != NULL);

// 		// Check if the allocated memory is zeroed
// 		assert(memcmp(res_ft, res_std, count * size) == 0);
// 	}

// 	free(res_ft);
// 	free(res_std);
// }

// int main()
// {
// 	// Test cases
// 	test_ft_calloc(0, 10);
// 	test_ft_calloc(10, 0);
// 	test_ft_calloc(10, sizeof(long));
// 	test_ft_calloc(5, 20);
// 	test_ft_calloc(100, 1);

// 	printf("All tests passed.\n");
// 	return (0);
// }

// #include <stdlib.h>
// #include <stdio.h>
// int main()
// {
// 	char *a = malloc(0);
// 	free(a);
// 	printf("ok");
// }
