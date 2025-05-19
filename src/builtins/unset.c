#include "../main.h"

int unset(t_command *command, t_shellvar *vars) {
	char *key = command->args[1];
	if (!key || !*key || (!ft_isalpha(key[0]) && key[0] != '_'))
		return (ft_putstr_fd("Invalid key", STDERR_FILENO), 1);
	t_shellvar *current = vars;
	t_shellvar *prvs = NULL;
	while (current) {
		if (!my_strcmp(current->key, key)) {
			if (prvs)
				prvs->next = current->next;
			else
				vars = current->next;
			free(current->key);
			free(current->value);
			free(current);
			return 0;
		}
		prvs = current;
		current = current->next;
	}
	// ft_putstr_fd("Variable not found", STDERR_FILENO);
	return 1;
}
