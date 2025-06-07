#include "../main.h"

int **setuppipes(int len) {
	int **matrix = malloc(len * sizeof(int *));
	for (int i = 0; i < len; i++)
		matrix[i] = malloc(2 * sizeof(int));
	for (int i = 0; i < len; i++) {
		if (pipe(matrix[i]) == -1) {
			for (int j = 0; j < len; j++)
				free(matrix[j]);
			free(matrix);
			return NULL;
		}
	}
	return matrix;
}

int cmdlen(t_command *cmd) {
	int i = 0;
	while (cmd != NULL) {
		i++;
		cmd = cmd->next;
	}
	return i;
}

void freepipes(int **pipes, int len) {
	if (!pipes)
		return;

	for (int i = 0; i < len; i++) {
		if (pipes[i]) {
			// Close pipe ends if they're still open
			close(pipes[i][0]);
			close(pipes[i][1]);
			free(pipes[i]);
		}
	}
	free(pipes);
}
