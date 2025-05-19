#include "../main.h"
#include <string.h>

// TODO if malloc fails free previous shit and return NULL
t_shellvar *envtoll(char **env) {
	if (!env)
		return NULL;
	t_shellvar *head = malloc(sizeof(t_shellvar));
	t_shellvar *curr = head;
	for (int i = 0; env[i]; i++) {
		char **s = ft_split(env[i], '=');
		curr->key = strdup(s[0]);
		curr->value = strdup(s[1]);
		curr->exported = true;
		if (env[i + 1] == NULL)
			curr->next = NULL;
		else
			curr->next = malloc(sizeof(t_shellvar));
		curr = curr->next;
		freematrix(s);
	}

	return head;
}

char *getvar(char *key, t_shellvar *vars) {
	if (!key || !vars)
		return NULL;
	while (vars != NULL) {
		if (!my_strcmp(key, vars->key))
			return vars->value;
		vars = vars->next;
	}
	return NULL;
}
