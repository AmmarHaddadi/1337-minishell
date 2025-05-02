/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:13:52 by ahaddadi          #+#    #+#             */
/*   Updated: 2024/11/09 15:45:29 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
	// ft_strncmp("Hello", NULL, 3);
	// strncmp("Hello", NULL, 3);

	// ft_strncmp(NULL, "NULL", 3);
	// strncmp(NULL, "NULL", 3);
// }

// #include <stdio.h>
// #include <string.h>

// // Function declaration
// int ft_strncmp(const char *s1, const char *s2, size_t n);

// // Test cases
// void test_ft_strncmp() {
// 	const char *s1;
// 	const char *s2;
// 	size_t n;
// 	int result;
// 	int expected;

// 	// Test case 1: Equal strings, n less than length
// 	s1 = "Hello";
// 	s2 = "Hello";
// 	n = 3;
// 	result = ft_strncmp(s1, s2, n);
// 	expected = strncmp(s1, s2, n);
// 	if (result == expected) {
// 		printf("Test 1 - passed\n");
// 	} else {
// 		printf("Test 1 - failed\n");
// 	}

// 	// Test case 2: Equal strings, n greater than length
// 	s1 = "Hello";
// 	s2 = "Hello";
// 	n = 10;
// 	result = ft_strncmp(s1, s2, n);
// 	expected = strncmp(s1, s2, n);
// 	if (result == expected) {
// 		printf("Test 2 - passed\n");
// 	} else {
// 		printf("Test 2 - failed\n");
// 	}

// 	// Test case 3: Different strings, n less than length
// 	s1 = "Hello";
// 	s2 = "Hellp";
// 	n = 4;
// 	result = ft_strncmp(s1, s2, n);
// 	expected = strncmp(s1, s2, n);
// 	if (result == expected) {
// 		printf("Test 3 - passed\n");
// 	} else {
// 		printf("Test 3 - failed\n");
// 	}

// 	// Test case 4: Different strings, n greater than length
// 	s1 = "Hello";
// 	s2 = "Hellp";
// 	n = 10;
// 	result = ft_strncmp(s1, s2, n);
// 	expected = strncmp(s1, s2, n);
// 	if (result == expected) {
// 		printf("Test 4 - passed\n");
// 	} else {
// 		printf("Test 4 - failed\n");
// 	}

// 	// Test case 5: Empty strings
// 	s1 = "";
// 	s2 = "";
// 	n = 5;
// 	result = ft_strncmp(s1, s2, n);
// 	expected = strncmp(s1, s2, n);
// 	if (result == expected) {
// 		printf("Test 5 - passed\n");
// 	} else {
// 		printf("Test 5 - failed\n");
// 	}

// 	// Test case 6: One empty string
// 	s1 = "Hello";
// 	s2 = "";
// 	n = 5;
// 	result = ft_strncmp(s1, s2, n);
// 	expected = strncmp(s1, s2, n);
// 	if (result == expected) {
// 		printf("Test 6 - passed\n");
// 	} else {
// 		printf("Test 6 - failed\n");
// 	}

// 	// Test case 7: n is zero
// 	s1 = "Hello";
// 	s2 = "Hello";
// 	n = 0;
// 	result = ft_strncmp(s1, s2, n);
// 	expected = strncmp(s1, s2, n);
// 	if (result == expected) {
// 		printf("Test 7 - passed\n");
// 	} else {
// 		printf("Test 7 - failed\n");
// 	}

// 	// Test case 8: Different strings, n is 1
// 	s1 = "Hello";
// 	s2 = "Jello";
// 	n = 1;
// 	result = ft_strncmp(s1, s2, n);
// 	expected = strncmp(s1, s2, n);
// 	if (result == expected) {
// 		printf("Test 8 - passed\n");
// 	} else {
// 		printf("Test 8 - failed\n");
// 	}
// }

// int main() {
// 	test_ft_strncmp();
// 	return (0);
// }
