#ifndef MAIN_H
#define MAIN_H


#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

enum red_mode {
	over_ride, // >
	append,	  // >>
	red_in,     // <
    red_heredoc, // <<
	no
};

typedef struct s_redir {
    char *filename;      // f1, f2, f3...
    enum red_mode red_mode;  // > || < || >> || <<
    struct s_redir *next;
} t_redir;

typedef struct s_command {
	char **args;			// Array of arguments ({"echo", NULL}) 
	t_redir *redirections; 
	struct s_command
		*next; // Pointer to the next command (for pipes), NULL if not
} t_command;

#endif




















// echo "abc" > f1 > f2 >> f3

// typedef struct s_file {
//     char            *name;
//     int                type;
//     struct s_file*    next;
// }t_file;

// typedef struct s_env {
//     char            *name;
//     char            *value;
//     struct s_env    *next;
// }t_env;

// typedef struct s_cmd {
//     char            **args; // Array of arguments ({"echo", NULL}) 
//     char            **file; // Array of arguments ({"f1", NULL}) 
//     struct s_cmd    *next;
// }t_cmd;

// typedef struct s_command
// {
//     t_env*            env;
//     t_cmd*            cmd;
//     unsigned char exit_status;
// };
