#include "../main.h"

void sigint_handler(int signum) {
	(void)signum;
	printf("\nexit\n");
	exit(0);
}

// check if all is white spaces
bool all_whitespace(char *input) {
	if (!*input)
		return true;
	int i;
	i = 0;
	while (input[i]) {
		if (input[i] != ' ' && input[i] != '\n')
			return (false);
		i++;
	}
	return (true);
	free(input);
}
