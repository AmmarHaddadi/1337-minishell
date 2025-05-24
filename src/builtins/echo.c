#include "../main.h"

static bool nflag(char **arr) {
	int i = 1;
	while (arr[i] != NULL) {
		if (!my_strcmp(arr[i], "-n"))
			return true;
		i++;
	}
	return false;
}

int echo(t_command *command) {
	int i = 1;
	bool n = nflag(command->args);
	while (command->args[i] != NULL) {
		if (my_strcmp(command->args[i], "-n")) {
			if (!command->args[i + 1])
				printf("%s", command->args[i]);
			else
				printf("%s ", command->args[i]);
		}
		i++;
	}
	if (!n)
		write(1, "\n", 1);
	return 0;
}
