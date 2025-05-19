#include "../main.h"

// returns a matrix of paths where the binary exists
char *getvalidpath(t_command *cmd, char *path) {
	char **paths = ft_split(path, ':');
	char *valid = NULL;
	if (paths) {
		for (int i = 0; paths[i]; i++) {
			char *joined = triplejoin(paths[i], "/", cmd->args[0]);
			if (access(joined, X_OK) == 0) {
				valid = ft_strdup(joined);
				free(joined);
				break;
			}
			free(joined);
		}
		freematrix(paths);
	}
	if (!valid && access(cmd->args[0], X_OK) == 0)
		valid = ft_strdup(cmd->args[0]);
	return valid;
}
