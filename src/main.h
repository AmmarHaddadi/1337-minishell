#ifndef MAIN_H
#define MAIN_H

#include "builtins/builtins.h"
#include "libft/libft.h"
# include "parsing/parsing.h"
#include <stdio.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_shellvar {
	char *key;
	char *value;
	bool exported;
	struct s_shellvar *next;
} t_shellvar;

enum red_mode {
	override,
	append,
	in,
} t_red_mode;

typedef struct s_redir {
	char *filename;
	enum red_mode red_mode;
	struct s_redir *next;
} t_redir;

typedef struct s_command {
	char **args;
	t_redir *redirections;
	struct s_command *next;
} t_command;

// utils
int my_strcmp(const char *s1, const char *s2);
int matrixlen(char **matrix);
void freematrix(char **m);
char *triplejoin(char *a, char *b, char *c);
t_token				*ft_lstlast(t_token *lst);
t_command			*push_struct(t_token *tokens);
t_redir				*ft_lstnew_redir(void *file, int mode);
void				ft_lstadd_back_redir(t_redir **lst, t_redir *new);
void				ft_lstadd_back_cmd(t_command **lst, t_command *new);
t_command			*split_commands_tokens(char *input);
void	sigint_handler(int signum);
int	check_space_newline(char *input);
#endif
