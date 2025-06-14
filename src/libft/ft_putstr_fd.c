/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:18:22 by ahaddadi          #+#    #+#             */
/*   Updated: 2024/10/28 10:28:31 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	if (fd >= 0)
	{
		while (*s)
			write(fd, s++, 1);
	}
}

// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>
// #include <string.h>
// #include <stdlib.h>

// void test_ft_putstr_fd_append()
// {
// 	int fd;
// 	char buffer[100] = {0}; // Buffer to store the output

// 	// Create and open a temporary file with O_APPEND flag
// 	fd = open("tempfile.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
// 	if (fd < 0) {
// 		perror("Failed to open tempfile.txt");
// 		exit(EXIT_FAILURE);
// 	}

// 	// Write the first string to the file
// 	ft_putstr_fd("Hello", fd);

// 	// Write the second string to the file
// 	ft_putstr_fd(" World", fd);

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

// 	// Check if the content of the file is "Hello World"
// 	if (strcmp(buffer, "Hello World") == 0) {
// 		printf("Test passed: Content is 'Hello World'.\n");
// 	} else {
// 		printf("Test failed: Expected 'Hello World', but got '%s'.\n", buffer);
// 	}

// 	// Close and remove the temporary file
// 	close(fd);
// 	remove("tempfile.txt");
// }

// int main()
// {
// 	test_ft_putstr_fd_append();
// 	return (0);
// }
