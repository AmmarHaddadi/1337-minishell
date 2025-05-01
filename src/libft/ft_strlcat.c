/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:36:30 by ahaddadi          #+#    #+#             */
/*   Updated: 2024/11/08 17:12:43 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (dstsize == 0 || d_len >= dstsize)
		return (dstsize + s_len);
	i = 0;
	while (src[i] && (d_len + i) < dstsize - 1)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
	// if src, dst or both are null, strlcat segfaults
	// char src[] = ", World!";
	// char dst[50] = "Hello";
	// printf("normal: %lu\n", strlcat(NULL, NULL, 4));
	// printf("normal: %s\n", dst);

	// char dst2[50] = "Hello";
	// printf("ft: %lu\n", ft_strlcat(NULL, src, 4));
	// printf("ft: %s\n", dst2);
// }

// #include <assert.h>
// #include <string.h>
// #include <stdio.h>

// // Test function prototypes
// void test_ft_strlcat_normal();
// void test_ft_strlcat_no_space();
// void test_ft_strlcat_zero_size();
// void test_ft_strlcat_empty_dst();
// void test_ft_strlcat_empty_src();

// int main() {
// 	test_ft_strlcat_normal();
// 	test_ft_strlcat_no_space();
// 	test_ft_strlcat_zero_size();
// 	test_ft_strlcat_empty_dst();
// 	test_ft_strlcat_empty_src();

// 	printf("All tests passed!\n");
// 	return (0);
// }

// void test_ft_strlcat_normal() {
// 	char dst1[20] = "Hello";
// 	char dst2[20] = "Hello";
// 	const char *src = " World";
// 	size_t result1 = ft_strlcat(dst1, src, sizeof(dst1));
// 	size_t result2 = strlcat(dst2, src, sizeof(dst2));
// 	assert(result1 == result2);
// 	assert(strcmp(dst1, dst2) == 0);
// }

// void test_ft_strlcat_no_space() {
// 	char dst1[10] = "Hello";
// 	char dst2[10] = "Hello";
// 	const char *src = " World";
// 	size_t result1 = ft_strlcat(dst1, src, 10);
// 	size_t result2 = strlcat(dst2, src, 10);
// 	assert(result1 == result2);
// 	assert(strcmp(dst1, dst2) == 0);
// }

// void test_ft_strlcat_zero_size() {
// 	char dtsx[10] = "Hello";
// 	char dstx2[10] = "Hello";
// 	const char *srcx = " World";
// 	size_t result1 = ft_strlcat(dtsx, srcx, 0);
// 	size_t result2 = strlcat(dstx2, srcx, 0);
// 	// printf("r1: %lu \n", result1);
// 	// printf("r2: %lu \n", result2);
// 	assert(result1 == result2);
// 	assert(strcmp(dtsx, dstx2) == 0);
// }

// void test_ft_strlcat_empty_dst() {
// 	char dst1[20] = "";
// 	char dst2[20] = "";
// 	const char *src = "Hello";
// 	size_t result1 = ft_strlcat(dst1, src, sizeof(dst1));
// 	size_t result2 = strlcat(dst2, src, sizeof(dst2));
// 	assert(result1 == result2);
// 	assert(strcmp(dst1, dst2) == 0);
// }

// void test_ft_strlcat_empty_src() {
// 	char dst1[20] = "Hello";
// 	char dst2[20] = "Hello";
// 	const char *src = "";
// 	size_t result1 = ft_strlcat(dst1, src, sizeof(dst1));
// 	size_t result2 = strlcat(dst2, src, sizeof(dst2));
// 	assert(result1 == result2);
// 	assert(strcmp(dst1, dst2) == 0);
// }
