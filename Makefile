CFLAGS = -Wall -Wextra -Werror -I/Users/ssallami/.brew/opt/readline/include
LDFLAGS = -L/usr/local/lib -lreadline

all:
	cc $(CFLAGS) src/minishell.c -o minishell $(LDFLAGS)
