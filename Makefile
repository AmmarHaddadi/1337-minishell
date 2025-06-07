SRC = $(shell find src -type f -name "*.c")
CFLAGS = -Wall -Wextra -Werror 
RDL = $(shell brew --prefix readline)
LDFLAGS = -lreadline -L$(RDL)/lib -I$(RDL)/lib
HDR = src/minishell.h src/parsing/parsing.h src/execution/execution.h src/builtins/builtins.h
NAME = minishell

OBJS = $(SRC:.c=.o)

all: $(OBJS)
	@make -C src/libft
	cc $(CFLAGS) $(OBJS) src/libft/libft.a -o $(NAME) $(LDFLAGS)

%.o : %.c $(HDR)
	cc $(CFLAGS) -c $< -o $@

clean:
	@make clean -C src/libft
	rm -rf $(OBJS)

fclean: clean
	@make fclean -C src/libft
	rm -rf $(NAME)

re: fclean all
