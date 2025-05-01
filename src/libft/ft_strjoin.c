/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 08:06:47 by ahaddadi          #+#    #+#             */
/*   Updated: 2024/11/09 10:49:12 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	sz;
	char	*s12;

	if (!s1 || !s2)
		return (NULL);
	sz = ft_strlen(s1) + ft_strlen(s2) + 1;
	s12 = malloc(sz);
	if (!s12)
		return (NULL);
	ft_strlcpy(s12, s1, sz);
	ft_strlcat(s12, s2, sz);
	return (s12);
}

// segfault testing
// #include <stdio.h>

// int main()
// {
// 	printf("%s\n", ft_strjoin("NULL", "NULL"));
// }

// #include <stdio.h>
// int main()
// {
// 	printf("%s\n", ft_strjoin("", ""));
// }

// #include <assert.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Test function prototypes
// void test_ft_strjoin_normal();
// void test_ft_strjoin_empty_first();
// void test_ft_strjoin_empty_second();
// void test_ft_strjoin_both_empty();
// void test_ft_strjoin_null_first();
// void test_ft_strjoin_null_second();
// void test_ft_strjoin_both_null();

// int main() {
// 	test_ft_strjoin_normal();
// 	test_ft_strjoin_empty_first();
// 	test_ft_strjoin_empty_second();
// 	test_ft_strjoin_both_empty();
// 	test_ft_strjoin_null_first();
// 	test_ft_strjoin_null_second();
// 	test_ft_strjoin_both_null();

// 	printf("All tests passed!\n");
// 	return (0);
// }

// void test_ft_strjoin_normal() {
// 	const char *s1 = "Hello";
// 	const char *s2 = " World";
// 	char *result = ft_strjoin(s1, s2);
// 	assert(result != NULL);
// 	assert(strcmp(result, "Hello World") == 0);
// 	free(result);
// }

// void test_ft_strjoin_empty_first() {
// 	const char *s1 = "";
// 	const char *s2 = "World";
// 	char *result = ft_strjoin(s1, s2);
// 	assert(result != NULL);
// 	// printf("result: %s\n", result);
// 	assert(strcmp(result, "World") == 0);
// 	free(result);
// }

// void test_ft_strjoin_empty_second() {
// 	const char *s1 = "Hello";
// 	const char *s2 = "";
// 	char *result = ft_strjoin(s1, s2);
// 	assert(result != NULL);
// 	assert(strcmp(result, "Hello") == 0);
// 	free(result);
// }

// void test_ft_strjoin_both_empty() {
// 	const char *s1 = "";
// 	const char *s2 = "";
// 	char *result = ft_strjoin(s1, s2);
// 	// printf("result both empty : %s\n", result);
// 	assert(result != NULL);
// 	assert(strcmp(result, "") == 0);
// 	free(result);
// }

// void test_ft_strjoin_null_first() {
// 	const char *s1 = NULL;
// 	const char *s2 = "World";
// 	char *result = ft_strjoin(s1, s2);
// 	assert(result == NULL);
// }

// void test_ft_strjoin_null_second() {
// 	const char *s1 = "Hello";
// 	const char *s2 = NULL;
// 	char *result = ft_strjoin(s1, s2);
// 	assert(result == NULL);
// }

// void test_ft_strjoin_both_null() {
// 	const char *s1 = NULL;
// 	const char *s2 = NULL;
// 	char *result = ft_strjoin(s1, s2);
// 	assert(result == NULL);
// }
