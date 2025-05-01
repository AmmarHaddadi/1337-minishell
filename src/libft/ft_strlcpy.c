/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:26:27 by ahaddadi          #+#    #+#             */
/*   Updated: 2024/11/08 17:14:44 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize > 0)
	{
		i = 0;
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (ft_strlen(src));
}

// #include <stdio.h>
// #include <string.h>
// #include <stddef.h>
// int main()
// {
	// char src[] = "Hello, World!";
	// char dst[50];
	// int x = strlcpy(NULL, src, 4);
	// printf("normal: %d\n", x);
	// printf("normal: %s\n", dst);

	// char dst2[50];
	// int y = ft_strlcpy(NULL, src, 4);
	// printf("ft: %d\n", y);
	// printf("ft: %s\n", dst2);
// }

// #include <stdio.h>
// #include <string.h>

// // Test cases
// void test_ft_strlcpy() {
// 	char dst[20];
// 	const char *src;
// 	size_t result;

// 	// Test case 1: Sufficient size
// 	src = "Hello, World!";
// 	result = ft_strlcpy(dst, src, sizeof(dst));
// 	if (strcmp(dst, src) == 0 && result == strlen(src)) {
// 		printf("Test 1 - passed\n");
// 	} else {
// 		printf("Test 1 - failed\n");
// 	}

// 	// Test case 2: Zero size
// 	strcpy(dst, "Initial");
// 	src = "Hello, World!";
// 	result = ft_strlcpy(dst, src, 0);
// 	if (strcmp(dst, "Initial") == 0 && result == strlen(src)) {
// 		printf("Test 2 - passed\n");
// 	} else {
// 		printf("Test 2 - failed\n");
// 	}

// 	// Test case 3: Smaller size
// 	src = "Hello, World!";
// 	result = ft_strlcpy(dst, src, 6);
// 	if (strcmp(dst, "Hello") == 0 && result == strlen(src)) {
// 		printf("Test 3 - passed\n");
// 	} else {
// 		printf("Test 3 - failed\n");
// 	}

// 	// Test case 4: Empty string
// 	src = "";
// 	result = ft_strlcpy(dst, src, sizeof(dst));
// 	if (strcmp(dst, src) == 0 && result == strlen(src)) {
// 		printf("Test 4 - passed\n");
// 	} else {
// 		printf("Test 4 - failed\n");
// 	}
// }

// int main() {
// 	test_ft_strlcpy();
// 	return (0);
// }
