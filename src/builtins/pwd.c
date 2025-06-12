/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 21:39:42 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/06/07 21:39:42 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

int	pwd(void)
{
	char		*path;
	extern int	errno;

	path = getcwd(NULL, 0);
	if (!path)
		return (perror("pwd"), 1);
	printf("%s\n", path);
	free(path);
	return (0);
}
