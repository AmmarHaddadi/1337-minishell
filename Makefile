SRC = $(shell find src -type f -name "*.c")
CFLAGS = -Wall -Wextra -Werror  -I/Users/$(shell echo $$USER)/.brew/opt/readline/include
LDFLAGS = -L/usr/local/lib -lreadline
# -fsanitize=address -g
NAME = minishell

OBJS = $(SRC:.c=.o)

all: $(OBJS)
	@make -C src/libft
	cc $(CFLAGS) $(OBJS) src/libft/libft.a -o $(NAME) $(LDFLAGS)

%.o : %.c src/minishell.h src/parsing/parsing.h
	cc $(CFLAGS) -c $< -o $@

clean:
	@make clean -C src/libft
	rm -rf $(OBJS)

fclean: clean
	@make fclean -C src/libft
	rm -rf $(NAME)

re: fclean all
