/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:27:40 by ahaddadi          #+#    #+#             */
/*   Updated: 2024/11/08 15:11:35 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n-- > 0)
		*str++ = 0;
}

// #include <assert.h>
// #include <string.h>
// #include <stdio.h>

// void test_ft_bzero() {
// 	// Test case: Normal case
// 	char str1[50] = "Hello, World!";
// 	char str2[50] = "Hello, World!";
// 	bzero(str1, 5);
// 	ft_bzero(str2, 5);
// 	assert(memcmp(str1, str2, 50) == 0);

// 	// Test case: Setting zero bytes
// 	char str3[50] = "Hello, World!";
// 	char str4[50] = "Hello, World!";
// 	bzero(str3, 0);
// 	ft_bzero(str4, 0);
// 	assert(memcmp(str3, str4, 50) == 0);

// 	// Test case: Setting entire string
// 	char str5[50] = "Hello, World!";
// 	char str6[50] = "Hello, World!";
// 	bzero(str5, strlen(str5));
// 	ft_bzero(str6, strlen(str6));
// 	assert(memcmp(str5, str6, 50) == 0);

// 	// Test case: Null pointer with zero length
// 	char *str7 = NULL;
// 	char *str8 = NULL;
// 	bzero(str7, 0);
// 	ft_bzero(str8, 0);
// 	// No assertion needed, just checking for segfault

// 	// Test case: Null pointer with non-zero length (should segfault)
// 	// Uncommenting the following lines will likely cause a segfault
// 	char *str9 = NULL;
// 	char *str10 = NULL;
// 	// bzero(str9, 5);
// 	// ft_bzero(str10, 5);
// 	// No assertion needed, just checking for segfault

// 	printf("All tests passed!\n");
// }

// int main() {
// 	test_ft_bzero();
// 	return 0;
// }
