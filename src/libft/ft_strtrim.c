/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 08:26:12 by ahaddadi          #+#    #+#             */
/*   Updated: 2024/11/09 11:23:25 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static int	inset(const char c, char const *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	char		*trimmed;

	if (!s1)
		return (NULL);
	else if (!set || ft_strlen(s1) == 0)
		return (ft_strdup(s1));
	start = 0;
	while (s1[start] && inset(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && inset(s1[end], set))
		end--;
	trimmed = ft_substr(s1, start, end - start + 1);
	return (trimmed);
}

// segfault test
// #include <stdio.h>

// int main()
// {
// 	char *s1 = "NULL";
// 	char *set = NULL;
// 	char *trimmed = ft_strtrim(s1, set);
// 	printf("%s\n", trimmed);
// 	return (0);
// }

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <assert.h>

// char *ft_strtrim(const char *s1, const char *set);

// // Test case 1: Trim leading and trailing spaces
// void test_trim_spaces() {
// 	const char *s1 = "   hello world   ";
// 	const char *set = " ";
// 	char *trimmed = ft_strtrim(s1, set);
// 	assert(strcmp(trimmed, "hello world") == 0);
// 	free(trimmed);
// }

// // Test case 2: Trim leading and trailing tabs
// void test_trim_tabs() {
// 	const char *s1 = "\t\t\tgoodbye world\t\t\t";
// 	const char *set = "\t";
// 	char *trimmed = ft_strtrim(s1, set);
// 	assert(strcmp(trimmed, "goodbye world") == 0);
// 	free(trimmed);
// }

// // Test case 3: Trim leading and trailing newlines
// void test_trim_newlines() {
// 	const char *s1 = "\n\n\nwelcome to the jungle\n\n\n";
// 	const char *set = "\n";
// 	char *trimmed = ft_strtrim(s1, set);
// 	assert(strcmp(trimmed, "welcome to the jungle") == 0);
// 	free(trimmed);
// }

// // Test case 4: Trim leading and trailing spaces, tabs, and newlines
// void test_trim_mixed() {
// 	const char *s1 = " \t\n  hello world \t\n  ";
// 	const char *set = " \t\n";
// 	char *trimmed = ft_strtrim(s1, set);
// 	assert(strcmp(trimmed, "hello world") == 0);
// 	free(trimmed);
// }

// // Test case 5: Trim empty string
// void test_trim_empty() {
// 	const char *s1 = "";
// 	const char *set = " \t\n";
// 	char *trimmed = ft_strtrim(s1, set);
// 	assert(strcmp(trimmed, "") == 0);
// 	free(trimmed);
// }

// // Test case 6: No characters to trim
// void test_no_trim() {
// 	const char *s1 = "hello world";
// 	const char *set = " \t\n";
// 	char *trimmed = ft_strtrim(s1, set);
// 	assert(strcmp(trimmed, "hello world") == 0);
// 	free(trimmed);
// }

// // Test case 7: All characters to trim
// void test_all_trim() {
// 	const char *s1 = " \t\n ";
// 	const char *set = " \t\n";
// 	char *trimmed = ft_strtrim(s1, set);
// 	assert(strcmp(trimmed, "") == 0);
// 	free(trimmed);
// }

// // Test case 8: NULL input string
// void test_null_input_string() {
// 	const char *s1 = NULL;
// 	const char *set = " \t\n";
// 	char *trimmed = ft_strtrim(s1, set);
// 	assert(trimmed == NULL);
// }

// // Test case 9: NULL set string
// void test_null_set_string() {
// 	const char *s1 = "hello world";
// 	const char *set = NULL;
// 	char *trimmed = ft_strtrim(s1, set);
// 	assert(trimmed == NULL);
// }

// // Test case 10: Both NULL strings
// void test_both_null_strings() {
// 	const char *s1 = NULL;
// 	const char *set = NULL;
// 	char *trimmed = ft_strtrim(s1, set);
// 	assert(trimmed == NULL);
// }

// int main() {
// 	test_trim_spaces();
// 	test_trim_tabs();
// 	test_trim_newlines();
// 	test_trim_mixed();
// 	test_trim_empty();
// 	test_no_trim();
// 	test_all_trim();
// 	test_null_input_string();
// 	// test_null_set_string();
// 	test_both_null_strings();
// 	printf("all passed");
// 	return (0);
// }

/////////       unit 2
// #include <assert.h>
// #include <string.h>
// #include <stdio.h>

// void test_ft_strtrim() {
//     // Case 1: Basic trimming
//     char *result = ft_strtrim("  hello  ", " ");
//     assert(strcmp(result, "hello") == 0);
//     free(result);

//     // Case 2: Trimming with multiple characters in set
//     result = ft_strtrim("--hello--world--", "-");
//     assert(strcmp(result, "hello--world") == 0);
//     free(result);

//     // Case 3: Set with multiple different characters
//     result = ft_strtrim("**##hello##**", "*#");
//     assert(strcmp(result, "hello") == 0);
//     free(result);

//     // Case 4: No characters to trim (set is empty)
//     result = ft_strtrim("  hello  ", "");
//     assert(strcmp(result, "  hello  ") == 0);
//     free(result);

//     // Case 5: Set is NULL (should return a copy of s1)
//     result = ft_strtrim("  hello  ", NULL);
//     assert(strcmp(result, "  hello  ") == 0);
//     free(result);

//     // Case 6: s1 is NULL (should return NULL)
//     result = ft_strtrim(NULL, " ");
//     assert(result == NULL);

//     // Case 7: s1 is empty
//     result = ft_strtrim("", " ");
//     assert(strcmp(result, "") == 0);
//     free(result);

//     // Case 8: Entire string is in set (should return an empty string)
//     result = ft_strtrim("####", "#");
//     assert(strcmp(result, "") == 0);
//     free(result);

//     printf("All test cases passed!\n");
// }

// int main() {
//     test_ft_strtrim();
//     return (0);
// }
