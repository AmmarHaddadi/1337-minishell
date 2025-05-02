/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:01:39 by ahaddadi          #+#    #+#             */
/*   Updated: 2024/11/08 15:54:26 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*head;
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d == s)
		return (dst);
	head = d;
	while (n-- > 0)
		*d++ = *s++;
	return (head);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	// char src[] = "Hello, World!";
// 	// char dest[50];
// 	// ft_memcpy(dest, src, 5);
// 	printf("%s\n", memcpy(NULL, NULL, 5));
// 	return 0;
// }

// #include <assert.h>
// #include <string.h>
// #include <stdio.h>

// void test_ft_memcpy() {
// 	// Test case: Normal case
// 	char src1[50] = "Hello, World!";
// 	char dst1[50];
// 	char src2[50] = "Hello, World!";
// 	char dst2[50];
// 	assert(memcpy(dst1, src1, 13) == dst1);
// 	assert(ft_memcpy(dst2, src2, 13) == dst2);
// 	// printf("dst1: %s\n", dst1);
// 	// printf("dst2: %s\n", dst2);
// 	// printf( "%d", memcmp(dst1, dst2, 50) == 0);

// 	// Test case: Copy zero bytes
// 	char src3[50] = "Hello, World!";
// 	char dst3[50] = "Initial";
// 	char src4[50] = "Hello, World!";
// 	char dst4[50] = "Initial";
// 	assert(memcpy(dst3, src3, 0) == dst3);
// 	assert(ft_memcpy(dst4, src4, 0) == dst4);
// 	assert(memcmp(dst3, dst4, 50) == 0);

// 	// Test case: Source and destination are the same
// 	char src5[50] = "Hello, World!";
// 	char src6[50] = "Hello, World!";
// 	assert(memcpy(src5, src5, 13) == src5);
// 	assert(ft_memcpy(src6, src6, 13) == src6);
// 	assert(memcmp(src5, src6, 50) == 0);

// 	// Test case: Null source and destination with zero length
// 	char *src7 = NULL;
// 	char *dst7 = NULL;
// 	char *src8 = NULL;
// 	char *dst8 = NULL;
// 	assert(memcpy(dst7, src7, 0) == dst7);
// 	assert(ft_memcpy(dst8, src8, 0) == dst8);
// 	// No assertion needed, just checking for segfault

// 	// Test case: Null source and destination with non-zero length
//  (should segfault)
// 	// Uncommenting the following lines will likely cause a segfault
// 	// char *src9 = NULL;
// 	// char *dst9 = NULL;
// 	// char *src10 = NULL;
// 	// char *dst10 = NULL;
// 	// assert(memcpy(dst9, src9, 5) == dst9);
// 	// assert(ft_memcpy(dst10, src10, 5) == dst10);
// 	// No assertion needed, just checking for segfault

// 	printf("All tests passed!\n");
// }

// int main() {
// 	test_ft_memcpy();
// 	return 0;
// }
