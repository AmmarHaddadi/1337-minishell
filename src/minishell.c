#include "execution/execution.h"
#include "main.h"
#include <string.h>

int main(int ac, char **av, char **env) {
	(void)ac;
	(void)av;

	// char *input;
	int exit_code = 0;
	t_shellvar *vars = envtoll(env);

}
