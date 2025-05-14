#ifndef PARSING_H
# define PARSING_H


typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_REDIR_APPEND,
	TOKEN_HEREDOC,
}					t_token_type;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	int				has_space;
	struct s_token	*next;
}					t_token;

t_token				*tokens(char *input);
t_token				*ft_split_lexer(char *str);
void				ft_lstadd_back(t_token **lst, t_token *new);
t_token				*ft_lstnew(void *content);
int	ft_lstsize_token(t_token *lst);

#endif