/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:33:21 by ahaddadi          #+#    #+#             */
/*   Updated: 2024/11/09 16:58:37 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Function prototype for ft_striteri
// void ft_striteri(char *s, void (*f)(unsigned int, char *));

// // Sample function to be used with ft_striteri
// void sample_function(unsigned int i, char *c) {
// 	*c = *c + i;
// }

// // Function that converts to uppercase
// void to_uppercase(unsigned int i, char *c) {
// 	(void)i; // Unused parameter
// 	if (*c >= 'a' && *c <= 'z') {
// 		*c = *c - 32;
// 	}
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
// 	char str1[] = "abc";
// 	char str2[] = "";
// 	char str3[] = "abc";
// 	char str4[] = "abc";

// 	// Test case 1: Normal case
// 	ft_striteri(str1, sample_function);
// 	print_test_result("Test 1 - Normal case", strcmp(str1, "ace") == 0);

// 	// Test case 2: Empty string
// 	ft_striteri(str2, sample_function);
// 	print_test_result("Test 2 - Empty string", strcmp(str2, "") == 0);

// 	// Test case 3: Null input string
// 	ft_striteri(NULL, sample_function);
// 	print_test_result("Test 3 - Null input string", 1); // Should not crash

// 	// Test case 4: Null function pointer
// 	ft_striteri(str3, NULL);
// 	print_test_result("Test 4 - Null function pointer", strcmp(str3,
			// "abc") == 0); // Should not modify the string

// 	// Test case 5: Function that converts to uppercase
// 	ft_striteri(str4, to_uppercase);
// 	print_test_result("Test 5 - To uppercase", strcmp(str4, "ABC") == 0);

// 	return (0);
// }
