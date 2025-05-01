/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:54:22 by ahaddadi          #+#    #+#             */
/*   Updated: 2024/11/09 12:37:59 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>
// #include <string.h>
// #include <stdlib.h>

// void test_ft_putchar_fd()
// {
// 	int fd;
// 	char buffer[2] = {0};
		// Buffer to store the output character and null terminator

// 	// Create a temporary file
// 	fd = open("tempfile.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
// 	if (fd < 0) {
// 		perror("Failed to open tempfile.txt");
// 		exit(EXIT_FAILURE);
// 	}

// 	// Test writing a character to the file
// 	ft_putchar_fd('A', fd);

// 	// Rewind the file descriptor to the beginning
// 	lseek(fd, 0, SEEK_SET);

// 	// Read the character from the file
// 	if (read(fd, buffer, 1) < 0) {
// 		perror("Failed to read from tempfile.txt");
// 		close(fd);
// 		remove("tempfile.txt");
// 		exit(EXIT_FAILURE);
// 	}

// 	// Check if the character written is 'A'
// 	if (strcmp(buffer, "A") == 0) {
// 		printf("Test passed: Character 'A'
// 				was correctly written to the file.\n");
// 	} else {
// 		printf("Test failed: Expected 'A', but got '%s'.\n", buffer);
// 	}

// 	// Close and remove the temporary file
// 	close(fd);
// 	// remove("tempfile.txt");
// }

// int main()
// {
// 	test_ft_putchar_fd();
// 	return (0);
// }
