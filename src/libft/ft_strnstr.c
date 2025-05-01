/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:30:31 by ahaddadi          #+#    #+#             */
/*   Updated: 2024/11/08 19:08:14 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*n;
	const char	*h;
	size_t		l;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		n = needle;
		h = haystack;
		l = len;
		while (*h == *n && *n && l-- > 0)
		{
			h++;
			n++;
		}
		if (*n == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}

// segfault test
// #include <string.h>
// #include <stdio.h>
// int main()
// {
	// char *x = strnstr("bbr1bar2bar3", NULL, 10); //SEGFAULT
	// char *x = strnstr(NULL, "NULL", 10); //SEGFAULT
	// char *x = strnstr(NULL, NULL, 10); //SEGFAULT
	// ft
	// char *x = ft_strnstr("bbr1bar2bar3", NULL, 10); //SEGFAULT
	// char *x = ft_strnstr(NULL, "NULL", 10); //SEGFAULT
	// char *x = ft_strnstr(NULL, NULL, 10); //SEGFAULT
	// printf("%s",x);
// }

// #include <stdio.h>
// const char *largestring = "bbr1bar2bar3";
// const char *smallstring = "zed";

// int main()
// {
// 	printf("%s",ft_strnstr(largestring, smallstring, 10));
// }

// #include <stdio.h>
// #include <string.h>
// #include <assert.h>

// // Test function prototypes
// void test_ft_strnstr_found();
// void test_ft_strnstr_not_found();
// void test_ft_strnstr_empty_needle();
// void test_ft_strnstr_length_limit();
// void test_ft_strnstr_partial_match();

// int main() {
// 	test_ft_strnstr_found();
// 	test_ft_strnstr_not_found();
// 	test_ft_strnstr_empty_needle();
// 	test_ft_strnstr_length_limit();
// 	test_ft_strnstr_partial_match();

// 	printf("All tests passed!\n");
// 	return (0);
// }

// void test_ft_strnstr_found() {
// 	const char *haystack = "Hello, World!";
// 	const char *needle = "World";
// 	size_t len = 13;

// 	char *result1 = strnstr(haystack, needle, len);
// 	char *result2 = ft_strnstr(haystack, needle, len);

// 	assert(result1 == result2);
// 	printf("test_ft_strnstr_found passed\n");
// }

// void test_ft_strnstr_not_found() {
// 	const char *haystack = "Hello, World!";
// 	const char *needle = "xyz";
// 	size_t len = 13;

// 	char *result1 = strnstr(haystack, needle, len);
// 	char *result2 = ft_strnstr(haystack, needle, len);

// 	assert(result1 == result2);
// 	printf("test_ft_strnstr_not_found passed\n");
// }

// void test_ft_strnstr_empty_needle() {
// 	const char *haystack = "Hello, World!";
// 	const char *needle = "";
// 	size_t len = 13;

// 	char *result1 = strnstr(haystack, needle, len);
// 	char *result2 = ft_strnstr(haystack, needle, len);

// 	assert(result1 == result2);
// 	printf("test_ft_strnstr_empty_needle passed\n");
// }

// void test_ft_strnstr_length_limit() {
// 	const char *haystack = "Hello, World!";
// 	const char *needle = "World";
// 	size_t len = 5;

// 	char *result1 = strnstr(haystack, needle, len);
// 	char *result2 = ft_strnstr(haystack, needle, len);

// 	assert(result1 == result2);
// 	printf("test_ft_strnstr_length_limit passed\n");
// }

// void test_ft_strnstr_partial_match() {
// 	const char *haystack = "Hello, World!";
// 	const char *needle = "Wor";
// 	size_t len = 7;

// 	char *result1 = strnstr(haystack, needle, len);
// 	char *result2 = ft_strnstr(haystack, needle, len);

// 	assert(result1 == result2);
// 	printf("test_ft_strnstr_partial_match passed\n");
// }
