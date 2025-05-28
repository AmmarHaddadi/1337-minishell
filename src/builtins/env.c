#include "../main.h"

// HINT prints exported vars that have a value
int env(t_shellvar *vars) {
	while (vars != NULL) {
		if (vars->exported == true && vars->value != NULL) {
			ft_putstr_fd(vars->key, STDOUT_FILENO);
			ft_putstr_fd("=", STDOUT_FILENO);
			ft_putstr_fd(vars->value, STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
		}
		vars = vars->next;
	}
	return 0;
}

// Helper function to count exported variables
static int count_exported(t_shellvar *vars) {
	int count = 0;
	while (vars) {
		if (vars->exported)
			count++;
		vars = vars->next;
	}
	return count;
}

// Converts linked list to NULL-terminated array of key=value strings
// needed for execve
char **varstomatrix(t_shellvar *vars) {
	int count = count_exported(vars);
	char **env_array = malloc((count + 1) * sizeof(char *));
	if (!env_array)
		return NULL;

	int i = 0;
	while (vars) {
		if (vars->exported == true) {
			env_array[i] = triplejoin(vars->key, "=", vars->value);
			if (!env_array[i]) {
				for (int j = 0; j < i; j++)
					free(env_array[j]);
				free(env_array);
				return NULL;
			}
			i++;
		}
		vars = vars->next;
	}
	env_array[i] = NULL;
	return env_array;
}
