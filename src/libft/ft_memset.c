/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:40:35 by ahaddadi          #+#    #+#             */
/*   Updated: 2024/11/08 14:23:00 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)b;
	while (i < len)
		str[i++] = (unsigned char)c;
	return (str);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char str1[50] = "Hello, World!";
// 	// ft_memset(str1, 0, -2);
// 	memset(str1, 0, -2);
// }

// test_ft_memset.c
// #include <assert.h>
// #include <string.h>
// #include <stdio.h>

// void test_ft_memset() {
// 	// Test case: Normal case
// 	char str1[50] = "Hello, World!";
// 	char str2[50] = "Hello, World!";
// 	// assert(memset(str1, 'A', 5) == ft_memset(str2, 'A', 5));
// 	// assert(strcmp(str1, str2) == 0);
// 	printf("%s\n", memset(str1, 'A', 5));
// 	printf("%s\n", ft_memset(str2, 'A', 5));

// 	// // Test case: Setting zero bytes
// 	char str3[50] = "Hello, World!";
// 	char str4[50] = "Hello, World!";
// 	// assert(memset(str3, 'A', 0) == ft_memset(str4, 'A', 0));
// 	// assert(strcmp(str3, str4) == 0);
// 	printf("%s\n", memset(str3, 'A', 1));
// 	printf("%s\n", ft_memset(str4, 'A', 1));

// 	// // Test case: Setting entire string
// 	char str5[50] = "Hello, World!";
// 	char str6[50] = "Hello, World!";
// 	// assert(memset(str5, 'B', strlen(str5))
// == ft_memset(str6, 'B', strlen(str6)));
// 	// assert(strcmp(str5, str6) == 0);
// 	printf("%s\n", memset(str5, 'B', strlen(str5)));
// 	printf("%s\n", ft_memset(str6, 'B', strlen(str6)));

// 	// // Test case: Setting with null character
// 	char str7[50] = "Hello, World!";
// 	char str8[50] = "Hello, World!";
// 	// assert(memset(str7, '\0', 5) == ft_memset(str8, '\0', 5));
// 	// assert(memcmp(str7, str8, 50) == 0);
// 	printf("%s\n", memset(str7, '\0', 5));
// 	printf("%s\n", ft_memset(str8, '\0', 5));

// 	printf("All tests passed!\n");
// }

// int main() {
// 	test_ft_memset();
// 	return 0;
// }
