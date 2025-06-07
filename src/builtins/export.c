#include "../main.h"

// export VAR -> export=true
// export VAR=VAL -> export=true and update val || create

// updates/create shellvar
int updatevar(char *key, char *val, t_shellvar *vars, bool exported) {
	if (!vars)
		return 0;

	// updating logic
	t_shellvar *current = vars;
	t_shellvar *previous = NULL;
	while (current != NULL) {
		if (!my_strcmp(current->key, key)) {
			if (val) {
				free(current->value);
				current->value = ft_strdup(val);
			}
			current->exported = exported;
			return 0;
		}
		previous = current;
		current = current->next;
	}

	// creation logic
	previous->next = malloc(sizeof(t_shellvar));
	previous->next->key = ft_strdup(key);
	previous->next->value = ft_strdup(val);
	previous->next->exported = exported;
	previous->next->next = NULL;
	return 0;
}

int export(t_shellvar *vars, t_command *command) {
	// `export`
	if (command->args[1] == NULL) {
		bubble_sort_shellvars(vars);
		while (vars != NULL) {
			if (vars->exported == true) {
				ft_putstr_fd("declare -x ", STDOUT_FILENO);
				ft_putstr_fd(vars->key, STDOUT_FILENO);
				ft_putstr_fd("=\"", STDOUT_FILENO);
				ft_putstr_fd(vars->value, STDOUT_FILENO);
				ft_putstr_fd("\"\n", STDOUT_FILENO);
			}
			vars = vars->next;
		}
		return 0;
	}

	char **e = ft_split(command->args[1], '=');
	if (!ft_isalpha(e[0][0]) && e[0][0] != '_')
		return (freematrix(e), 1);
	// `export KEY=VAL`
	if (ft_strchr(command->args[1], '='))
		updatevar(e[0], e[1], vars, true);
	// `export KEY`
	else
		updatevar(e[0], NULL, vars, true);
	freematrix(e);
	return 0;
}
