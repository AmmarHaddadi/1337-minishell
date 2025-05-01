/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:18:47 by ahaddadi          #+#    #+#             */
/*   Updated: 2024/11/08 16:33:57 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

// we use s inestead of src bash tb9a 3ndna wa7d copy original for reference
// d < s -> d comes before s
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	if (dst <= src)
		dst = ft_memcpy(dst, src, len);
	else
	{
		d = (unsigned char *)dst;
		s = (unsigned char *)src;
		while (len-- > 0)
			d[len] = s[len];
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
	// char s[] = "123456789";
	// ft_memmove(s+2, s, sizeof(char) * 7);
	// printf("%s", s);
	// memmove(NULL,NULL, 5);
// }

// #include <stdio.h>
// #include <string.h>
// #include <assert.h>

// // Test function prototypes
// void test_ft_memmove_normal();
// void test_ft_memmove_overlap_forward();
// void test_ft_memmove_overlap_backward();
// void test_ft_memmove_empty();
// void test_ft_memmove_null();

// int main() {
// 	test_ft_memmove_normal();
// 	test_ft_memmove_overlap_forward();
// 	test_ft_memmove_overlap_backward();
// 	test_ft_memmove_empty();
// 	// test_ft_memmove_null();

// 	printf("All tests passed!\n");
// 	return (0);
// }

// void log_test(const char *test_name, const char *expected,
// 	const char *result, size_t len) {
// 	printf("Test: %s\n", test_name);
// 	printf("Expected: %.*s\n", (int)len, expected);
// 	printf("Result: %.*s\n", (int)len, result);
// 	printf("\n");
// }

// void test_ft_memmove_normal() {
// 	char src[] = "Hello, World!";
// 	char dst1[20];
// 	char dst2[20];

// 	memmove(dst1, src, 13);
// 	ft_memmove(dst2, src, 13);

// 	log_test("Normal", dst1, dst2, 13);
// 	assert(memcmp(dst1, dst2, 13) == 0);
// }

// void test_ft_memmove_overlap_forward() {
// 	char src1[] = "123456789";
// 	char src2[] = "123456789";

// 	memmove(src1 + 2, src1, 7);
// 	ft_memmove(src2 + 2, src2, 7);

// 	log_test("Overlap Forward", src1, src2, 9);
// 	assert(memcmp(src1, src2, 9) == 0);
// }

// void test_ft_memmove_overlap_backward() {
// 	char src1[] = "123456789";
// 	char src2[] = "123456789";

// 	memmove(src1, src1 + 2, 7);
// 	ft_memmove(src2, src2 + 2, 7);

// 	log_test("Overlap Backward", src1, src2, 9);
// 	assert(memcmp(src1, src2, 9) == 0);
// }

// void test_ft_memmove_empty() {
// 	char src1[] = "123456789";
// 	char src2[] = "123456789";

// 	memmove(src1, src1, 0);
// 	ft_memmove(src2, src2, 0);

// 	log_test("Empty", src1, src2, 9);
// 	assert(memcmp(src1, src2, 9) == 0);
// }

// void test_ft_memmove_null() {
// 	char *src1 = NULL;
// 	char *src2 = NULL;

// 	// memmove should handle NULL gracefully,
// 		// but we won't test it directly as it may cause undefined behavior.
// 	// Instead, we ensure ft_memmove also handles NULL gracefully.
// 	void *result1 = ft_memmove(src1, src2, 0);
// 	void *result2 = ft_memmove(src1, src2, 0);

// 	log_test("Null", (char *)result1, (char *)result2, 0);
// 	assert(result1 == result2);
// }

// ////// more tests
// fixing: [crash]: your memmove does not well
// with NULL as both parameters and size
// #include <stdio.h>
// #include <string.h>
// #include <assert.h>

// void test_memmove_zero_size() {
// 	// char src1[] = "123456789";
// 	// char dst1[10];
// 	// char src2[] = "123456789";
// 	// char dst2[10];

// 	// Using ft_memmove
// 	// ft_memmove(dst1, src1, 0);
// 	// printf("dst1: %s\n", dst1); // Print dst1

// 	// Using standard memmove
// 	memmove(((void *)0), ((void *)0), 5);
// 	// printf("original: %s\n", dst2); // Print dst2
// 	printf("original: %s\n", memmove(((void *)0), ((void *)0), 5));

// 	// Compare the results
// 	// assert(memcmp(dst1, dst2, 10) == 0);
// }

// int main() {
// 	test_memmove_zero_size();
// 	printf("All tests passed.\n");
// 	return (0);
// }
