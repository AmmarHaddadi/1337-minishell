# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 18:07:16 by ahaddadi          #+#    #+#              #
#    Updated: 2024/11/08 10:21:26 by ahaddadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS := -Wall -Wextra -Werror

C_FILES := ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
O_FILES := $(C_FILES:.c=.o)

C_FILES_BNS := ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
O_FILES_BNS := $(C_FILES_BNS:.c=.o)

NAME := libft.a

all: $(NAME)

%.o : %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(O_FILES)
	ar -rsc $@ $^

bonus: $(O_FILES_BNS)
	ar -rsc $(NAME) $(O_FILES_BNS)

clean:
	rm -rf $(O_FILES) $(O_FILES_BNS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
