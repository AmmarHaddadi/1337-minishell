/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:38:55 by ahaddadi          #+#    #+#             */
/*   Updated: 2024/11/08 12:47:17 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	printf("%lu",ft_strlen(NULL));
// }

// #include <assert.h>
// #include <string.h>
// #include <stdio.h>

// void test_ft_strlen() {
// 	// Test case: Empty string
// 	assert(ft_strlen("") == strlen(""));

// 	// Test case: Normal string
// 	assert(ft_strlen("Hello, World!") == strlen("Hello, World!"));

// 	// Test case: String with special characters
// 	assert(ft_strlen("Hello\nWorld\t!") == strlen("Hello\nWorld\t!"));

// 	// Test case: Very long string
// 	char long_str[1001];
// 	for (int i = 0; i < 1000; i++) {
// 		long_str[i] = 'a';
// 	}
// 	long_str[1000] = '\0';
// 	assert(ft_strlen(long_str) == strlen(long_str));

// 	// Test case: Null pointer (should handle gracefully)
// 	// Uncomment the following line to test for segfault
// 	// assert(ft_strlen(NULL) == strlen(NULL));
// 	// strlen(NULL);
// 	// ft_strlen(NULL);
// }

// int main() {
// 	test_ft_strlen();
// 	printf("All tests passed!\n");
// 	return 0;
// }
