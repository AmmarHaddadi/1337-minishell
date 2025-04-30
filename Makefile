SRC = src/minishell.c src/parsing/tokens.c src/tools/ft_lstnew.c src/tools/ft_lstadd_back.c src/tools/ft_split_lexer.c

CFLAGS = -Wall -Wextra -Werror -I/Users/ssallami/.brew/opt/readline/include

LDFLAGS = -L/usr/local/lib -lreadline

CC = cc

RM = rm -rf

NAME = minishell

OBJS = ${SRC:.c=.o}

all: ${OBJS}
	${CC} ${CFLAGS} ${OBJS}  -o ${NAME} ${LDFLAGS}

%.o : %.c src/minishell.h src/parsing/parsing.h
	${CC} ${CFLAGS} -c $< -o $@

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
