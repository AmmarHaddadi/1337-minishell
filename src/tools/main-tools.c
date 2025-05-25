#include "../main.h"

void	sigint_handler(int signum)
{
	(void)signum;
	printf("\nexit\n");
	exit(0);
}


int	check_space_newline(char *input)
{
	int	i;
	i = 0;
	while (input[i])
	{
		if (input[i] != ' ' && input[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}