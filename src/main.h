#ifndef MAIN_H
#define MAIN_H

#include "builtins/builtins.h"
#include "execution/execution.h"
#include "libft/libft.h"
#include <stdio.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_shellvar {
	char *key;
	char *value;
	bool exported; // if true pass to execve
	struct s_shellvar *next;
} t_shellvar;

enum red_mode {
	override, // >
	append,	  // >>
	in,		  // <
	none	  // no red
} t_red_mode;

typedef struct s_redir {
	char *filename; // filename || NULL
	enum red_mode red_mode;
	struct s_redir *next; // for multiple redirs like >f1 >f2
} t_redir;

typedef struct s_command {
	char **args; // array of args ({"ls", "-l", NULL})
	t_redir *redirections;
	struct s_command *next; // Next command (pipes) || NULL
} t_command;

// utils
int my_strcmp(const char *s1, const char *s2);
int matrixlen(char **matrix);
void freematrix(char **m);
char *triplejoin(char *a, char *b, char *c);
#endif
