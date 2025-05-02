/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:04:37 by ahaddadi          #+#    #+#             */
/*   Updated: 2024/11/08 14:01:05 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s11 = (const unsigned char *)s1;
	const unsigned char	*s22 = (const unsigned char *)s2;

	while (n-- > 0)
	{
		if (*s11 != *s22)
			return (*s11 - *s22);
		s11++;
		s22++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// #include <assert.h>

// int main() {
	// // FT memcmp segfault test
	// ft_memcmp(NULL, NULL, 0);
	// char str2[] = "abcdef";
	// ft_memcmp(NULL, str2, sizeof(str2));
	// char str3[] = "abcdeg";
	// ft_memcmp(str3, NULL, sizeof(str3));

	// memcmp(NULL, NULL, 0);
	// char str2[] = "abcdef";
	// memcmp(NULL, str2, sizeof(str2));
	// char str3[] = "abcdeg";
	// memcmp(str3, NULL, sizeof(str3));
	// memcmp(str3, str2, -1);
	// assert(memcmp(str3, str2, -1) == ft_memcmp(str3, str2, -1));
//     return 0;
// }

// #include <assert.h>
// #include <string.h>
// #include <stdio.h>

// void test_ft_memcmp() {
// 	// Test case: Identical strings
// 	char str1[] = "abcdef";
// 	char str2[] = "abcdef";
// 	assert(ft_memcmp(str1, str2, 6) == memcmp(str1, str2, 6));

// 	// Test case: Different strings
// 	char str3[] = "abcdef";
// 	char str4[] = "abcdeg";
// 	assert(ft_memcmp(str3, str4, 6) == memcmp(str3, str4, 6));

// 	// Test case: Different lengths
// 	char str5[] = "abcdef";
// 	char str6[] = "abcde";
// 	assert(ft_memcmp(str5, str6, 5) == memcmp(str5, str6, 5));

// 	// Test case: Empty strings
// 	char str7[] = "";
// 	char str8[] = "";
// 	assert(ft_memcmp(str7, str8, 0) == memcmp(str7, str8, 0));

// 	// Test case: Null character within the range
// 	char str9[] = "abc\0def";
// 	char str10[] = "abc\0deg";
// 	assert(ft_memcmp(str9, str10, 7) == memcmp(str9, str10, 7));

// 	// Test case: Comparing zero bytes
// 	char str11[] = "abcdef";
// 	char str12[] = "abcdef";
// 	assert(ft_memcmp(str11, str12, 0) == memcmp(str11, str12, 0));

// 	printf("All tests passed!\n");
// }

// int main() {
// 	test_ft_memcmp();
// 	return 0;
// }
