#ifndef MAIN_H
#define MAIN_H


#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "parsing/parsing.h"
#include "libft/libft.h"

enum red_mode {
	override, // >
	append,	  // >>
	red_in,     // <
    red_heredoc, // <<
	no
} t_red_mode;

typedef struct s_redir {
    char *filename;      // f1, f2, f3...
    enum red_mode red_mode ;  // > || < || >> || <<
    struct s_redir *next;
} t_redir;

typedef struct s_command {
	char **args;			// Array of arguments ({"echo", NULL}) 
	t_redir *redirections; 
	struct s_command
		*next; // Pointer to the next command (for pipes), NULL if not
} t_command;

t_token	*ft_lstlast2(t_token *lst);
#endif