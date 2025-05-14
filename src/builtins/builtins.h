typedef struct s_command t_command;
typedef struct s_shellvar t_shellvar;
#include <stdbool.h>

// builtins
int echo(t_command *command);
int cd(t_command *command);
int pwd();
int export(t_shellvar *vars, t_command *command);
int unset(t_command *command, t_shellvar *vars);
int env(t_shellvar *vars);
int builtin_exit(t_command *cmd);

// helpers
void bubble_sort_shellvars(t_shellvar *head);
int updatevar(char *key, char *val, t_shellvar *vars, bool exported);
void append_envs(char **env, t_shellvar *vars);
char **varstomatrix(t_shellvar *vars);
