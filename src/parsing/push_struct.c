

#include "../main.h"

static int	count_files(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens != NULL)
	{
		if (tokens->next != NULL && (tokens->type == TOKEN_REDIR_IN
				|| tokens->type == TOKEN_REDIR_OUT
				|| tokens->type == TOKEN_REDIR_APPEND
				|| tokens->type == TOKEN_HEREDOC)
			&& tokens->next->type == TOKEN_WORD)
			count++;
		tokens = tokens->next;
	}
	return (count);
}

static int	count_operator(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens != NULL)
	{
		if (tokens->next != NULL && (tokens->type == TOKEN_REDIR_IN
				|| tokens->type == TOKEN_REDIR_OUT
				|| tokens->type == TOKEN_REDIR_APPEND
				|| tokens->type == TOKEN_HEREDOC || tokens->type == TOKEN_PIPE))
			count++;
		tokens = tokens->next;
	}
	return (count);
}
static t_token	*search_mode(t_token *tokens)
{
	if (!tokens)
		return (NULL);
	while (tokens != NULL)
	{
		if (tokens->next != NULL && (tokens->type == TOKEN_REDIR_IN
				|| tokens->type == TOKEN_REDIR_OUT
				|| tokens->type == TOKEN_REDIR_APPEND
				|| tokens->type == TOKEN_HEREDOC))
			break ;
		tokens = tokens->next;
	}
	return (tokens);
}

t_command	*push_struct(t_token *tokens)
{
	t_command *cmd = malloc(sizeof(t_command));
	t_token *head = tokens;
	// t_token *original = head;

	if (!cmd)
		return (NULL);

	cmd->args = NULL;
	cmd->redirections = NULL;
	cmd->next = NULL;

	// push *redirections
	// 1 . count files
	int countFiles = count_files(tokens);
	int countOperator = count_operator(tokens);

	// 2 . while -> push *filename | red_mode
	t_token *tkn;

	
	while (tokens != NULL)
	{
		tkn = search_mode(tokens);
		if (tkn == NULL)
			break ;

		if (tkn->next != NULL)
		{
			ft_lstadd_back_redir(&cmd->redirections,ft_lstnew_redir(tkn->next->value, tkn->type));
			tkn->type = 10;
			tkn->next->type = 10;
			tokens = tkn->next->next;
		}
		else
			break ;
	}

	char **ptr = NULL;
	int countWords = ft_lstsize_token(head) - (countFiles + countOperator);

	ptr = (char **)malloc(sizeof(char *) * (countWords + 1));
	if (!ptr)
		return (NULL);

	int i = 0;
	while (i < countWords && head != NULL)
	{
		if (head->type == TOKEN_WORD)
		{
			ptr[i] = ft_strdup(head->value);
			i++;
		}
		head = head->next;
	}
	ptr[i] = NULL;

	cmd->args = ptr;

	return (cmd);
}
