/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:51:12 by ahaddadi          #+#    #+#             */
/*   Updated: 2024/11/09 17:17:05 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
	// printf("%s", srtrchr("a11a22a33", 'a'));
	// strrchr(NULL, 'a'); // Segmentation fault
	// ft_strrchr(NULL, 'a');
// }

// #include <stdio.h>
// #include <string.h>
// #include <assert.h>

// // Test function prototypes
// void test_ft_strrchr_found();
// void test_ft_strrchr_not_found();
// void test_ft_strrchr_null_char();
// void test_ft_strrchr_empty_string();
// void test_ft_strrchr_multiple_occurrences();

// int main()
// {
// 	test_ft_strrchr_found();
// 	test_ft_strrchr_not_found();
// 	test_ft_strrchr_null_char();
// 	test_ft_strrchr_empty_string();
// 	test_ft_strrchr_multiple_occurrences();

// 	printf("All tests passed!\n");
// 	return (0);
// }

// void test_ft_strrchr_found()
// {
// 	const char *str = "Hello, World!";
// 	char c = 'o';

// 	char *result1 = strrchr(str, c);
// 	char *result2 = ft_strrchr(str, c);
// 	assert(result1 == result2);
// 	printf("test_ft_strrchr_found passed\n");
// }

// void test_ft_strrchr_not_found()
// {
// 	const char *str = "Hello, World!";
// 	char c = 'x';

// 	char *result1 = strrchr(str, c);
// 	char *result2 = ft_strrchr(str, c);

// 	assert(result1 == result2);
// 	printf("test_ft_strrchr_not_found passed\n");
// }

// void test_ft_strrchr_null_char()
// {
// 	const char *str = "Hello, World!";
// 	char c = '\0';

// 	char *result1 = strrchr(str, c);
// 	char *result2 = ft_strrchr(str, c);

// 	assert(result1 == result2);
// 	printf("test_ft_strrchr_null_char passed\n");
// }

// void test_ft_strrchr_empty_string()
// {
// 	const char *str = "";
// 	char c = 'H';

// 	char *result1 = strrchr(str, c);
// 	char *result2 = ft_strrchr(str, c);

// 	assert(result1 == result2);
// 	printf("test_ft_strrchr_empty_string passed\n");
// }

// void test_ft_strrchr_multiple_occurrences()
// {
// 	const char *str = "a11a22a33";
// 	char c = 'a';

// 	char *result1 = strrchr(str, c);
// 	char *result2 = ft_strrchr(str, c);

// 	assert(result1 == result2);
// 	printf("test_ft_strrchr_multiple_occurrences passed\n");
// }
