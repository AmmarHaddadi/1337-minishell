/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:15:57 by ahaddadi          #+#    #+#             */
/*   Updated: 2024/11/09 11:59:24 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	tol(int n)
{
	int	tol;

	tol = 0;
	while (n > 0)
	{
		n /= 10;
		tol++;
	}
	return (tol);
}

char	*ft_itoa(int n)
{
	int		is_neg;
	int		len;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	is_neg = (n < 0);
	if (is_neg)
		n = -n;
	len = tol(n) + is_neg + 1;
	str = malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	len -= 1;
	str[len] = '\0';
	if (is_neg)
		str[0] = '-';
	while (n > 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		printf("%s", ft_itoa(atoi(argv[1])));
// 	}
// 	return (0);
// }

// tests

// #include <stdio.h>
// #include <string.h>
// #include <limits.h>

// void test_ft_itoa(int n, char *expected_result)
// {
// 	char *result = ft_itoa(n);
// 	if (strcmp(result, expected_result) == 0)
// 		printf("PASS: ft_itoa(%d) = %s\n", n, result);
// 	else
// 		printf("FAIL: ft_itoa(%d) = %s, expected: %s\n", n, result,
			// expected_result);
// 	free(result);
// }

// int main()
// {
// 	// Test cases
// 	test_ft_itoa(0, "0");
// 	test_ft_itoa(123, "123");
// 	test_ft_itoa(-456, "-456");
// 	test_ft_itoa(987654321, "987654321");
// 	test_ft_itoa(-987654321, "-987654321");
// 	test_ft_itoa(INT_MAX, "2147483647");
// 	test_ft_itoa(INT_MIN, "-2147483648");

// 	return (0);
// }
