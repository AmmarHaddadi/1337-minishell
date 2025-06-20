/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 08:15:18 by ssallami          #+#    #+#             */
/*   Updated: 2025/06/20 01:49:37 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef enum qt
{
	none,
	single,
	dbl
}							t_quote;

typedef enum e_token_type
{
	TOKEN_REDIR_OUT,
	TOKEN_REDIR_APPEND,
	TOKEN_REDIR_IN,
	TOKEN_HEREDOC,
	TOKEN_PIPE,
	TOKEN_WORD,
	TOKEN_WORD_EXPAND_HEREDOC,
}							t_token_type;

typedef struct s_token
{
	char					*value;
	t_token_type			type;
	int						has_space;
	int						has_quote_single;
	struct s_token			*next;
}							t_token;

typedef struct s_shellvar	t_shellvar;
t_token						*ft_split_lexer(char *str, t_shellvar *vars);
void						ft_lstadd_back(t_token **lst, t_token *new);
t_token						*ft_lstnew_token_add_type(void *content,
								int isword);
t_token						*ft_lstnew_token_add_mode(void *file, int mode);
int							ft_lstsize_token(t_token *lst);
void						free_tokens(t_token *tks);
char						*replace(char *input, t_shellvar *vars);
void						len_word(char *str, int *i);
t_token						*join_token_word(t_token *tokens);
int							count_files(t_token *tokens);
int							expand_dollar(char *buffer[2], int tab[2],
								t_quote *quote, t_shellvar *vars);
int							len_allocation(char *input, t_shellvar *vars);

#endif
