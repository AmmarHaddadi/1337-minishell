#ifndef MAIN_H
#define MAIN_H

enum red_mode {
	override, // >
	append,	  // >>
	no
};

typedef struct s_command {
	char **args;			// Array of arguments ({"ls", "-l", NULL})
	char *input;			// filname || NULL
	char *output;			// filename || NULL
	enum red_mode red_mode; // >> awla >
	struct s_command
		*next; // Pointer to the next command (for pipes), NULL if not
} t_command;

#endif
