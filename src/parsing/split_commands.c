#include "../main.h"

static int	count_pipe(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens != NULL)
	{
		if (tokens->type == TOKEN_PIPE)
			count++;
		tokens = tokens->next;
	}
	return (count);
}
static t_token	*split_commands(t_token *tokens)
{
	t_token	*new_token;

	new_token = NULL;
	while (tokens != NULL && tokens->type != TOKEN_PIPE)
	{
		ft_lstadd_back(&new_token, ft_lstnew_token_add_mode(tokens->value,
				tokens->type));
		tokens = tokens->next;
	}
	return (new_token);
}
static t_token	*search_mode(t_token *tokens)
{
	if (!tokens)
		return (NULL);
	while (tokens != NULL)
	{
		if (tokens->next != NULL && tokens->type == TOKEN_PIPE)
			break ;
		tokens = tokens->next;
	}
	return (tokens);
}

t_command	*split_commands_tokens(t_token *tks)
{
	t_command	*cmds;
	t_token		*pipe;
	t_command	*get_new_cmd;
	t_token		*next_cmd;
	int			countPipe;

	cmds = NULL;
	get_new_cmd = NULL;
	countPipe = count_pipe(tks);
	while (countPipe >= 0 && tks != NULL)
	{
		get_new_cmd = NULL;
		// 1. split cmd
		next_cmd = split_commands(tks);
		// 2. push cmd
		get_new_cmd = push_struct(next_cmd);
		ft_lstadd_back_cmd(&cmds, get_new_cmd);
		// 3. next pipe
		pipe = search_mode(tks);
		if (!pipe)
			break ;
		tks = pipe->next;
		countPipe--;
	}
	return (cmds);
}
