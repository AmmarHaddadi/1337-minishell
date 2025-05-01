/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:05:51 by ahaddadi          #+#    #+#             */
/*   Updated: 2024/11/09 17:38:35 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	wc(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n >= 0 && n <= 9)
		wc('0' + n, fd);
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		wc((n % 10) + '0', fd);
	}
	else if (n < 0)
	{
		wc('-', fd);
		ft_putnbr_fd(-n, fd);
	}
}

// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>
// #include <string.h>
// #include <stdlib.h>

// void test_ft_putnbr_fd(int n, const char *expected)
// {
// 	int fd;
// 	char buffer[100] = {0}; // Buffer to store the output

// 	// Create and open a temporary file
// 	fd = open("tempfile.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd < 0) {
// 		perror("Failed to open tempfile.txt");
// 		exit(EXIT_FAILURE);
// 	}

// 	// Write the number to the file
// 	ft_putnbr_fd(n, fd);

// 	// Close the file
// 	close(fd);

// 	// Reopen the file for reading
// 	fd = open("tempfile.txt", O_RDONLY);
// 	if (fd < 0) {
// 		perror("Failed to open tempfile.txt for reading");
// 		exit(EXIT_FAILURE);
// 	}

// 	// Read the content of the file
// 	read(fd, buffer, sizeof(buffer) - 1);

// 	// Check if the content of the file matches the expected output
// 	if (strcmp(buffer, expected) == 0) {
// 		printf("Test passed: %d -> '%s'\n", n, buffer);
// 	} else {
// 		printf("Test failed: %d -> Expected '%s', but got '%s'\n", n, expected,
			// buffer);
// 	}

// 	// Close and remove the temporary file
// 	close(fd);
// 	remove("tempfile.txt");
// }

// int main()
// {
// 	// Test cases
// 	test_ft_putnbr_fd(0, "0");
// 	test_ft_putnbr_fd(10, "10");
// 	test_ft_putnbr_fd(-10, "-10");
// 	test_ft_putnbr_fd(12345, "12345");
// 	test_ft_putnbr_fd(-12345, "-12345");
// 	test_ft_putnbr_fd(-2147483648, "-2147483648");
// 	test_ft_putnbr_fd(2147483647, "2147483647");

// 	return (0);
// }
