#include "../main.h"
#include <stdlib.h>

// export VAR -> export=true
// export VAR=VAL -> export=true and update val || create

// updates/create shellvar
int updatevar(char *key, char *val, t_shellvar *vars, bool exported) {
	// first char must be alpha
	if (!ft_isalpha(key[0]))
		return (ft_putstr_fd("Ivalid key", STDERR_FILENO), 1);

	// first time call m sure it can be optimized
	if (!vars) {
		vars = (t_shellvar *)malloc(sizeof(t_shellvar));
		vars->next = NULL;
		vars->next->key = ft_strdup(key);
		vars->next->value = ft_strdup(val);
		vars->next->exported = exported;
		return 0;
	}

	// updating logic
	t_shellvar *current = vars;
	while (current->next != NULL) {
		if (!my_strcmp(current->key, key)) {
			if (val) {
				free(current->value);
				current->value = ft_strdup(val);
			}
			current->exported = exported;
			return 0;
		}
		current = current->next;
	}

	// creation logic
	current->next = malloc(sizeof(t_shellvar));
	current->next->key = ft_strdup(key);
	current->next->value = ft_strdup(val);
	current->next->exported = exported;
	return 0;
}

// TODO at startup env should be appended to vars
int export(t_shellvar *vars, t_command *command) {
	// `export`
	if (command->args[1] == NULL) {
		// append_envs(env, vars);
		bubble_sort_shellvars(vars);
		while (vars != NULL) {
			if (vars->exported == true)
				printf("declare -x %s=\"%s\"", vars->key, vars->value);
			vars = vars->next;
		}
		return 0;
	}

	char **e = ft_split(command->args[1], '=');
	// `export KEY=VAL`
	// WARN what if `export a=` ??
	if (ft_strchr(command->args[1], '='))
		updatevar(e[0], e[1], vars, true);

	// `export KEY`
	else
		updatevar(e[0], NULL, vars, true);
	return 0;
}
