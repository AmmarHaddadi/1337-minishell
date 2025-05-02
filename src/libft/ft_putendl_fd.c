/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:56:48 by ahaddadi          #+#    #+#             */
/*   Updated: 2024/11/09 12:55:57 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	if (s && fd >= 0)
	{
		while (*s)
			write(fd, s++, 1);
		write(fd, "\n", 1);
	}
}

// #include <unistd.h>
// #include <stdio.h>
// #include <fcntl.h>

// void run_test(const char *test_name, char *s, const char *expected_file)
// {
// 	int test_fd = open(expected_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (test_fd < 0)
// 	{
// 		perror("open");
// 		printf("%s: Failed to open file\n", test_name);
// 		return ;
// 	}

// 	ft_putendl_fd(s, test_fd);
// 	close(test_fd);

// 	printf("%s: Passed\n", test_name);
// }

// int main(void)
// {
// 	// Test case 1: Normal string and valid file descriptor
// 	run_test("Test 1: Normal string and valid file descriptor", "Hello, World!",
// 		"test1.txt");

// 	// Test case 2: NULL string and valid file descriptor
// 	run_test("Test 2: NULL string and valid file descriptor", NULL,
// 		"test2.txt");

// 	// Test case 3: Empty string and valid file descriptor
// 	run_test("Test 3: Empty string and valid file descriptor", "", "test3.txt");

// 	// Test case 4: Normal string and invalid file descriptor
// 	run_test("Test 4: Normal string and invalid file descriptor",
// 		"This should not be written", "test4.txt");

// 	// Test case 5: NULL string and invalid file descriptor
// 	run_test("Test 5: NULL string and invalid file descriptor", NULL,
// 		"test5.txt");

// 	// Test case 6: Empty string and invalid file descriptor
// 	run_test("Test 6: Empty string and invalid file descriptor", "",
// 		"test6.txt");

// 	printf("Tests completed.\n");
// 	return (0);
// }
