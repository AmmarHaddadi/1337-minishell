#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include "libft/libft.h"
# include "parsing/parsing.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdlib.h>

typedef enum red_mode
{
	override,    // >
	append,      // >>
	red_in,      // <
	red_heredoc, // <<
	no
}					t_red_mode;

typedef struct s_redir
{
	char *filename;         // f1, f2, f3...
	enum red_mode red_mode; // > || < || >> || <<
	struct s_redir	*next;
}					t_redir;

typedef struct s_command
{
	char **args; // Array of arguments ({"echo", NULL})
	t_redir			*redirections;
	struct s_command *next;
		// Pointer to the next command (for pipes),NULL if not
}					t_command;

// utils
t_token				*ft_lstlast(t_token *lst);
t_command			*push_struct(t_token *tokens);
t_redir				*ft_lstnew_redir(void *file, int mode);
void				ft_lstadd_back_redir(t_redir **lst, t_redir *new);
void				ft_lstadd_back_cmd(t_command **lst, t_command *new);
t_command			*split_commands_tokens(t_token *tks);
void	sigint_handler(int signum);
int	check_space_newline(char *input);


#endif