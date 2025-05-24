#ifndef EXECUTION_H
#define EXECUTION_H
#include <stdbool.h>

typedef struct s_command t_command;
typedef struct s_shellvar t_shellvar;
typedef struct s_redir t_redir;
int execute(t_command *cmd, t_shellvar *vars);

// helper
char *getvalidpath(t_command *cmd, char *path);
bool setupfd(t_redir *red);
#endif
