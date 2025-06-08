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

void	write_fd(int fd, char *filename)
{
	char	*str;

	str = readline("> ");
	while (str && ft_strcmp(str, filename) != 0)
	{
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
		free(str);
		str = readline("> ");
	}
	free(str);
}

static void	write_files_heredoc(t_redir *redirections, int *index)
{
	t_redir	*tmp_redirections;
	char	*namefile;
	char	*creat_in_tmp;
	int		fd;
	char	*index_str;
	char	*tmp;

	tmp_redirections = redirections;
	while (tmp_redirections != NULL)
	{
		if (tmp_redirections->red_mode == heredoc)
		{
			index_str = ft_itoa((*index)++);
			tmp = ft_strjoin(tmp_redirections->filename, "-heredoc-");
			namefile = ft_strjoin(tmp, index_str);
			free(index_str);
			free(tmp);
			creat_in_tmp = ft_strjoin("/tmp/", namefile);
			fd = open(creat_in_tmp, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (fd == -1)
				perror("open");
			else
			{
				write_fd(fd, tmp_redirections->filename);
				close(fd);
			}
			free(namefile);
			free(tmp_redirections->filename);
			tmp_redirections->filename = creat_in_tmp;
		}
		tmp_redirections = tmp_redirections->next;
	}
}

void	prepare_heredocs(t_command *cmds)
{
	t_command	*tmp_cmds;
	int			index;

	tmp_cmds = cmds;
	index = 0;
	while (tmp_cmds != NULL)
	{
		write_files_heredoc(tmp_cmds->redirections, &index);
		tmp_cmds = tmp_cmds->next;
	}
}

t_command	*split_commands_tokens(char *input, t_shellvar *vars)
{
	t_command	*cmds;
	t_token		*pipe;
	t_command	*get_new_cmd;
	t_token		*next_cmd;
	int			countPipe;
	t_token		*tks;
	t_token		*tks_head;

	(void)vars;
	// TODO manage leaks in tks
	tks = tokens(input, vars);
	tks_head = tks;
	cmds = NULL;
	countPipe = count_pipe(tks);
	while (countPipe >= 0 && tks != NULL)
	{
		get_new_cmd = NULL;
		// 1. split cmd
		next_cmd = split_commands(tks);
		// 2. push cmd
		get_new_cmd = push_struct(next_cmd);
		free_tokens(next_cmd);
		ft_lstadd_back_cmd(&cmds, get_new_cmd);
		// 3. next pipe
		pipe = search_mode(tks);
		if (!pipe)
			break ;
		tks = pipe->next;
		countPipe--;
	}
	prepare_heredocs(cmds);
	free_tokens(tks_head);
	return (cmds);
}
