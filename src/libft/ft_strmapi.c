/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:35:38 by ahaddadi          #+#    #+#             */
/*   Updated: 2024/11/09 12:02:11 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mod;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	mod = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!mod)
		return (NULL);
	i = 0;
	while (s[i])
	{
		mod[i] = f(i, (char)s[i]);
		i++;
	}
	mod[i] = 0;
	return (mod);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Sample function to be used with ft_strmapi
// char sample_function(unsigned int i, char c) {
// 	return (c + i);
// }

// // Function that converts to uppercase
// char to_uppercase(unsigned int i, char c) {
// 	(void)i; // Unused parameter
// 	if (c >= 'a' && c <= 'z') {
// 		return (c - 32);
// 	}
// 	return (c);
// }

// // Helper function to print test results
// void print_test_result(const char *test_name, int condition) {
// 	if (condition) {
// 		printf("%s: PASSED\n", test_name);
// 	} else {
// 		printf("%s: FAILED\n", test_name);
// 	}
// }

// int main() {
// 	// Test case 1: Normal case
// 	char *result = ft_strmapi("abc", sample_function);
// 	print_test_result("Test 1 - Normal case", strcmp(result, "ace") == 0);
// 	free(result);

// 	// Test case 2: Empty string
// 	result = ft_strmapi("", sample_function);
// 	print_test_result("Test 2 - Empty string", strcmp(result, "") == 0);
// 	free(result);

// 	// Test case 3: Null input string
// 	result = ft_strmapi(NULL, sample_function);
// 	print_test_result("Test 3 - Null input string", result == NULL);

// 	// Test case 4: Null function pointer
// 	result = ft_strmapi("abc", NULL);
// 	print_test_result("Test 4 - Null function pointer", result == NULL);

// 	// Test case 5: Function that converts to uppercase
// 	result = ft_strmapi("abc", to_uppercase);
// 	print_test_result("Test 5 - To uppercase", strcmp(result, "ABC") == 0);
// 	free(result);

// 	return (0);
// }
