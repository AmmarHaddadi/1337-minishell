

#include "../main.h"
#include "parsing.h"

static int	count_files(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens != NULL)
	{
		if (  tokens->next != NULL && (tokens->type == TOKEN_REDIR_IN || tokens->type == TOKEN_REDIR_OUT
			|| tokens->type == TOKEN_REDIR_APPEND
			|| tokens->type == TOKEN_HEREDOC) && tokens->next->type == TOKEN_WORD)
            count++;
        tokens = tokens->next;
	}
    return count ;
}

static int	count_operator(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens != NULL)
	{
		if (  tokens->next != NULL && (tokens->type == TOKEN_REDIR_IN || tokens->type == TOKEN_REDIR_OUT
			|| tokens->type == TOKEN_REDIR_APPEND
			|| tokens->type == TOKEN_HEREDOC || tokens->type == TOKEN_PIPE ))
            count++;
        tokens = tokens->next;
	}
    return count ;
}

t_command	*push_struct(t_token *tokens)
{
	t_command *cmd = malloc(sizeof(t_command));
	if (!cmd)
		return (NULL);

	// push *redirections
	// 1 . count files
	int countFiles = count_files(tokens);
	int countType = count_operator(tokens);
    printf("count = %d  | count_operator = %d | = %d\n",countFiles,countType,ft_lstsize_token(tokens) - (countFiles + countType));
	// 2 . allocation
	// 3 . while -> push *filename | red_mode

	// push **args
	// 1 . count words = size_lst - count_filse
	// 2 . allocation
	// 3 . while -> push **args

	return (cmd);
}