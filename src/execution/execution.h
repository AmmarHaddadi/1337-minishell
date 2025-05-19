#ifndef EXECUTION_H
#define EXECUTION_H
typedef struct s_command t_command;
typedef struct s_shellvar t_shellvar;
int execute(t_command *cmd, t_shellvar *vars);

// helper
char *getvalidpath(t_command *cmd, char *path);
#endif
