# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 18:07:16 by ahaddadi          #+#    #+#              #
#    Updated: 2025/05/09 14:37:26 by ssallami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS := -Wall -Wextra -Werror

C_FILES := ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strcmp.c
O_FILES := $(C_FILES:.c=.o)

NAME := libft.a

all: $(NAME)

%.o : %.c libft.h
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(O_FILES)
	@ar -rsc $@ $^

clean:
	@rm -rf $(O_FILES)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
