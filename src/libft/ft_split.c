/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:59:02 by ahaddadi          #+#    #+#             */
/*   Updated: 2024/11/09 11:53:12 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static int	count_chunks(char *s, char del)
{
	int	count;
	int	in_chunk;

	count = 0;
	in_chunk = 0;
	while (*s)
	{
		if (*s == del)
			in_chunk = 0;
		else if (!in_chunk)
		{
			in_chunk = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	*create_chunk(char **str, char del)
{
	char	*chunk;
	char	*start;
	char	*end;

	start = *str;
	while (*start && *start == del)
		start++;
	end = start;
	while (*end && *end != del)
		end++;
	chunk = ft_substr(start, 0, end - start);
	*str = end;
	return (chunk);
}

static void	delall(char **chunks, int i)
{
	while (i >= 0)
	{
		free(chunks[i]);
		i--;
	}
	free(chunks);
}

char	**ft_split(char const *s, char c)
{
	int		chunk_count;
	char	**chunks;
	int		i;

	if (!s)
		return (NULL);
	chunk_count = count_chunks((char *)s, c);
	chunks = malloc(sizeof(char *) * (chunk_count + 1));
	if (!chunks)
		return (NULL);
	i = 0;
	while (i < chunk_count)
	{
		chunks[i] = create_chunk((char **)&s, c);
		if (!chunks[i])
		{
			delall(chunks, i - 1);
			return (NULL);
		}
		i++;
	}
	chunks[chunk_count] = NULL;
	return (chunks);
}

// segfault test
// #include <stdio.h>
// int main()
// {
// 	char **chunks = ft_split("", 0);
// 	if (chunks)
// 	{
// 		int i = 0;
// 		while (chunks[i])
// 		{
// 			printf("%s\n", chunks[i]);
// 			i++;
// 		}
// 	}
// 	else
// 		printf("Null pointer handled correctly.\n");
// 	return (0);
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Helper function to print chunks for debugging
// void print_chunks(char **chunks) {
// 	while (*chunks) {
// 		printf("%s\n", *chunks);
// 		chunks++;
// 	}
// }

// // Helper function to free chunks
// void free_chunks(char **chunks) {
// 	char **temp = chunks;
// 	while (*temp) {
// 		free(*temp);
// 		temp++;
// 	}
// 	free(chunks);
// }

// // Test case 1: Split by space
// void test_split_by_space() {
// 	const char *s = "hello world this is a test";
// 	char **chunks = ft_split(s, ' ');
// 	printf("Test case 1:\n");
// 	print_chunks(chunks);
// 	free_chunks(chunks);
// }

// // Test case 2: Split by comma
// void test_split_by_comma() {
// 	const char *s = "apple,banana,orange,grape";
// 	char **chunks = ft_split(s, ',');
// 	printf("Test case 2:\n");
// 	print_chunks(chunks);
// 	free_chunks(chunks);
// }

// // Test case 3: Split by newline
// void test_split_by_newline() {
// 	const char *s = "line1\nline2\nline3\nline4";
// 	char **chunks = ft_split(s, '\n');
// 	printf("Test case 3:\n");
// 	print_chunks(chunks);
// 	free_chunks(chunks);
// }

// // Test case 4: Split by space with leading and trailing spaces
// void test_split_with_spaces() {
// 	const char *s = "  hello   world  ";
// 	char **chunks = ft_split(s, ' ');
// 	printf("Test case 4:\n");
// 	print_chunks(chunks);
// 	free_chunks(chunks);
// }

// // Test case 5: Split empty string
// void test_split_empty_string() {
// 	const char *s = "";
// 	char **chunks = ft_split(s, ' ');
// 	printf("Test case 5:\n");
// 	print_chunks(chunks);
// 	free_chunks(chunks);
// }

// // Test case 6: Split string with no delimiter
// void test_split_no_delimiter() {
// 	const char *s = "helloworld";
// 	char **chunks = ft_split(s, ' ');
// 	printf("Test case 6:\n");
// 	print_chunks(chunks);
// 	free_chunks(chunks);
// }

// // Test case 7: Split string with only delimiters
// void test_split_only_delimiters() {
// 	const char *s = ";;;;;";
// 	char **chunks = ft_split(s, ';');
// 	printf("Test case 7:\n");
// 	print_chunks(chunks);
// 	free_chunks(chunks);
// }

// // Test case 8: Null pointer input
// void test_split_null_pointer() {
// 	const char *s = NULL;
// 	char **chunks = ft_split(s, ' ');
// 	printf("Test case 8:\n");
// 	if (chunks == NULL) {
// 		printf("Null pointer handled correctly.\n");
// 	} else {
// 		print_chunks(chunks);
// 		free_chunks(chunks);
// 	}
// }

// // Test case 9: Single character string
// void test_split_single_char() {
// 	const char *s = "a";
// 	char **chunks = ft_split(s, ' ');
// 	printf("Test case 9:\n");
// 	print_chunks(chunks);
// 	free_chunks(chunks);
// }

// int main() {
// 	test_split_by_space();
// 	test_split_by_comma();
// 	test_split_by_newline();
// 	test_split_with_spaces();
// 	test_split_empty_string();
// 	test_split_no_delimiter();
// 	test_split_only_delimiters();
// 	test_split_null_pointer();
// 	test_split_single_char();
// 	return (0);
// }
