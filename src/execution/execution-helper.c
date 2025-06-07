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

bool setupfd(t_redir *red) {
	t_redir *redir = red;
	if (!redir)
		return true;

	// creating output files
	while (redir != NULL) {
		if (redir->red_mode == override || redir->red_mode == append) {
			int fd = open(redir->filename, O_CREAT, 0644);
			if (fd < 0)
				return false;
			close(fd);
		}
		redir = redir->next;
	}

	// findig last out redir and it's mode
	char *redfile = NULL;
	redir = red; // used for looping
	int outmode;
	while (redir != NULL) {
		if (redir->red_mode == override) {
			redfile = redir->filename;
			outmode = O_TRUNC;
		} else if (redir->red_mode == append) {
			redfile = redir->filename;
			outmode = O_APPEND;
		}
		redir = redir->next;
	}

	// changing the out if needed
	int ofd;
	if (redfile) {
		ofd = open(redfile, outmode | O_WRONLY, 0644);
		if (ofd < 0)
			return (perror("Can't open output file"), false);
		if (dup2(ofd, STDOUT_FILENO) < 0)
			return (perror("Can't forward output to file"), close(ofd), false);
	}

	// changing the in
	redir = red; // used for looping
	redfile = NULL;
	while (redir != NULL) {
		if (redir->red_mode == in) {
			redfile = redir->filename;
			break;
		}
		redir = redir->next;
	}

	// no in file found
	if (!redfile)
		return true;

	// changing the in
	int ifd = open(redfile, O_RDONLY);
	if (ifd < 0)
		return (perror("Can't open output file"), close(ofd), false);
	if (dup2(ifd, STDIN_FILENO) < 0)
		return (perror("Can't read input"), close(ofd), close(ifd), false);
	return true;
}

static void freeredirs(t_redir *red) {
	t_redir *prvs;
	while (red != NULL) {
		prvs = red;
		red = red->next;
		free(prvs->filename);
		free(prvs);
	}
}

void freecmd(t_command *cmd) {
	t_command *prvs;
	while (cmd != NULL) {
		prvs = cmd;
		cmd = cmd->next;
		freematrix(prvs->args);
		freeredirs(prvs->redirections);
		free(prvs);
	}
}
