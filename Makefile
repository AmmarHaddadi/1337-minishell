SRC = src/minishell.c src/parsing/tokens.c src/tools/ft_lstnew.c src/tools/ft_lstadd_back.c src/tools/ft_lstaddback.c  src/tools/ft_split_lexer.c

CFLAGS = -Wall -Wextra -Werror -I/Users/ssallami/.brew/opt/readline/include

LDFLAGS = -L/usr/local/lib -lreadline

CC = cc

RM = rm -rf

NAME = minishell

OBJS = ${SRC:.c=.o}

all: ${OBJS}
	@make -C src/libft
	@make bonus -C src/libft
	${CC} ${CFLAGS} ${OBJS} src/libft/libft.a  -o ${NAME} ${LDFLAGS}

%.o : %.c src/minishell.h src/parsing/parsing.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
	@make clean -C src/libft
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
