/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:46:07 by ahaddadi          #+#    #+#             */
/*   Updated: 2024/11/08 17:20:24 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	total;
	int	sign;

	total = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
		total = total * 10 + (*str++ - '0');
	return (total * sign);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
	// printf("%d", ft_atoi(NULL));
	// printf("%d", atoi(NULL)); //segfaults
// }

// #include <stdio.h>
// #include <stdlib.h> // For the original atoi
// #include <limits.h>
// #include "libft.h" // Assuming ft_atoi is declared in libft.h

// void test_atoi_functions(const char *str)
// {
// 	int result_ft_atoi = ft_atoi(str);
// 	int result_atoi = atoi(str);

// 	if (result_ft_atoi == result_atoi)
// 		printf("PASS: ft_atoi(\"%s\") = %d, atoi(\"%s\") = %d\n", str,
			// result_ft_atoi, str, result_atoi);
// 	else
// 		printf("FAIL: ft_atoi(\"%s\") = %d, atoi(\"%s\") = %d\n", str,
			// result_ft_atoi, str, result_atoi);
// }

// int main()
// {
// 	// Basic tests
// 	test_atoi_functions("123");
// 	test_atoi_functions("-123");
// 	test_atoi_functions("+123");
// 	test_atoi_functions("0");

// 	// Tests with leading spaces
// 	test_atoi_functions("   123");
// 	test_atoi_functions("   -123");
// 	test_atoi_functions("   +123");

// 	// Tests with non-digit characters
// 	test_atoi_functions("123abc");
// 	test_atoi_functions("-123abc");
// 	test_atoi_functions("+123abc");

// 	// Edge cases
// 	test_atoi_functions("2147483647"); // INT_MAX
// 	test_atoi_functions("-2147483648"); // INT_MIN

// 	// Overflow cases (behavior may vary depending on implementation)
// 	test_atoi_functions("2147483648"); // INT_MAX + 1
// 	test_atoi_functions("-2147483649"); // INT_MIN - 1

// 	return (0);
// }
