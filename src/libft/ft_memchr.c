/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:36:23 by ahaddadi          #+#    #+#             */
/*   Updated: 2024/11/08 13:33:15 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ss;

	ss = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*ss == (unsigned char)c)
			return (ss);
		ss++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
	// memchr(NULL, 'e', 3);
	// ft_memchr(NULL, 'e', 3);
// }

// #include <assert.h>
// #include <string.h>
// #include <stdio.h>

// void test_ft_memchr() {
// 	// Test case: Character found within the range
// 	char str1[] = "b1a22a33";
// 	assert(ft_memchr(str1, 'a', 4) == memchr(str1, 'a', 4));

// 	// Test case: Character not found within the range
// 	char str2[] = "b1a22a33";
// 	assert(ft_memchr(str2, 'x', 4) == memchr(str2, 'x', 4));

// 	// Test case: Character found at the end of the range
// 	char str3[] = "b1a22a33";
// 	assert(ft_memchr(str3, '2', 5) == memchr(str3, '2', 5));

// 	// Test case: Character found at the beginning of the range
// 	char str4[] = "b1a22a33";
// 	assert(ft_memchr(str4, 'b', 1) == memchr(str4, 'b', 1));

// 	// Test case: Empty string
// 	char str5[] = "";
// 	assert(ft_memchr(str5, 'a', 0) == memchr(str5, 'a', 0));

// 	// Test case: Null character within the range
// 	char str6[] = "b1a\022a33";
// 	assert(ft_memchr(str6, '\022', 5) == memchr(str6, '\022', 5));

// 	printf("All tests passed!\n");
// }

// int main() {
// 	test_ft_memchr();
// 	return 0;
// }
