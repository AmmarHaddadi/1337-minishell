#include "../main.h"

// NOTE at very first copy env var to the LL to be able to unset and modify
int unset(t_command *command, t_shellvar *vars) {
	char *key = command->args[1];
	if (!ft_isalpha(*key))
		return (ft_putstr_fd("Ivalid key", STDERR_FILENO), 1);

	t_shellvar *current = vars;
	t_shellvar *prvs;
	// WARN what if it's the first??
	while (current->next != NULL) {
		if (!my_strcmp(current->key, key)) {
			free(current->key);
			free(current->value);
			prvs->next = current->next;
			free(current);
			return 0;
		}
		t_shellvar *prvs = current;
		current = current->next;
	}
	return 0;
}
