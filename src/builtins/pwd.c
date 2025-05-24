#include "../main.h"
// #include <cstdio>

extern int errno;

int pwd() {
	char *path = getcwd(NULL, 0);
	if (!path)
		return (perror("pwd"), 1);
	printf("%s\n", path);
	free(path);
	return 0;
}
