SRC =	src/minishell.c src/signals.c src/utils.c src/utils2.c \
		src/builtins/cd.c src/builtins/echo.c src/builtins/env-helper.c src/builtins/env.c src/builtins/exit.c src/builtins/export-helper.c src/builtins/export.c src/builtins/pwd.c src/builtins/unset.c \
		src/execution/execution-helper.c src/execution/execution-helper2.c src/execution/execution.c src/execution/pipes-helper.c src/execution/setupfds.c src/execution/setupfds2.c \
		src/parsing/count_files.c src/parsing/free_tokens.c src/parsing/ft_split_lexer.c src/parsing/join_token_word.c src/parsing/len_word.c src/parsing/prepare_heredocs.c src/parsing/push_struct.c src/parsing/replace.c src/parsing/split_commands.c src/parsing/tokens.c src/parsing/expand_dollar.c src/parsing/len_allocation.c src/parsing/skip_sgl_dbl.c src/parsing/handle_heredoc_process.c \
		src/tools/ft_lstadd_back.c src/tools/ft_lstlast.c src/tools/ft_lstnew.c src/tools/ft_lstsize.c src/tools/main-tools.c 
OBJS = $(SRC:.c=.o)
LIBFT = src/libft/libft.a
CFLAGS = -Wall -Wextra -Werror 
RDL = $(shell brew --prefix readline)
LDFLAGS = -lreadline -L$(RDL)/lib -I$(RDL)/lib
HDR = src/builtins/builtins.h src/execution/execution.h src/libft/libft.h src/main.h src/parsing/parsing.h src/signals.h 
NAME = minishell


all: $(OBJS) $(LIBFT)
	cc $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(LDFLAGS)

$(LIBFT):
	@make -C src/libft

%.o : %.c $(HDR)
	@cc $(CFLAGS) -c $< -o $@

clean:
	@make clean -C src/libft
	@rm -rf $(OBJS)

fclean: clean
	@make fclean -C src/libft
	@rm -rf $(NAME)

re: fclean all

rdln:
	brew install readline
