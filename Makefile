SRC = $(shell find src -type f -name "*.c")
CFLAGS = -Wall -Wextra -Werror

NAME = minishell

OBJS = $(SRC:.c=.o)

all: $(OBJS)
	@make -C src/libft
	cc $(CFLAGS) $(OBJS) src/libft/libft.a -o $(NAME)

%.o : %.c src/minishell.h
	cc $(CFLAGS) -c $< -o $@

clean:
	@make clean -C src/libft
	rm $(OBJS)

fclean: clean
	@make fclean -C src/libft
	rm $(NAME)

re: fclean all
