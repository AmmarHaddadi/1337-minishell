#include "main.h"
#include <string.h>

int my_strcmp(const char *s1, const char *s2) {
	while (*s1 && (*s1 == *s2)) {
		s1++;
		s2++;
	}
	return *(unsigned char *)s1 - *(unsigned char *)s2;
}

int matrixlen(char **matrix) {
	int i = 0;
	if (!matrix || !*matrix)
		return 0;
	while (matrix[i] != NULL)
		i++;
	return i;
}

void freematrix(char **m) {
	int i = 0;
	while (m[i] != NULL)
		free(m[i++]);
	free(m);
}

char *triplejoin(char *a, char *b, char *c) {
	size_t sz;
	char *full;

	if (!a || !b || !c)
		return (NULL);
	sz = ft_strlen(a) + ft_strlen(b) + ft_strlen(c) + 1;
	full = malloc(sz);
	if (!full)
		return (NULL);
	ft_strlcpy(full, a, sz);
	ft_strlcat(full, b, sz);
	ft_strlcat(full, c, sz);
	return (full);
}
