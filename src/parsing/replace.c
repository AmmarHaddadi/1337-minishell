
#include "../main.h"

static t_quote	update_quote(char c, t_quote current)
{
	if (c == '\'' && current == none)
		return (single);
	if (c == '\'' && current == single)
		return (none);
	if (c == '\"' && current == none)
		return (dbl);
	if (c == '\"' && current == dbl)
		return (none);
	return (current);
}

static int	handle_dollar_case(char *s, t_quote q, t_shellvar *vars, int *len)
{
	int		j;
	char	*key;
	char	*tmp;
	char	*val;

	if ((q == none || q == dbl) && (ft_isalpha(s[1]) || s[1] == '_'
			|| s[1] == '?' || !s[1]))
	{
		j = 1;
		while (ft_isalnum(s[j]) || s[j] == '_' || s[j] == '?')
			j++;
		key = ft_substr(s, 1, j - 1);
		tmp = getvar(key, vars);
		if (tmp != NULL)
			val = ft_strdup(tmp);
		else
			val = ft_strdup("");
		*len += ft_strlen(val);
		free(key);
		free(val);
		return (j - 1);
	}
	if (q == none && (s[1] == '\'' || s[1] == '"'))
		return (0);
	if (ft_isdigit(s[1]))
		return (1);
	return (0);
}
static int	len_allocation(char *input, t_shellvar *vars)
{
	t_quote	quote;
	int		i;
	int		str_len;

	quote = none;
	str_len = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '"' || input[i] == '\'')
			quote = update_quote(input[i], quote);
		else if (input[i] == '$')
			i += handle_dollar_case(input + i, quote, vars, &str_len);
		else
			str_len++;
		i++;
	}
	return (str_len);
}
/////////////////////////////////////////////////////////////

static int	is_valid_dollar_char(char c)
{
	return (ft_isalpha(c) || ft_isdigit(c) || c == '_' || c == '?');
}

static char	*get_val(char *input, int i, int *skip, t_shellvar *vars)
{
	int		j;
	char	*key;
	char	*tmp;
	char	*val;

	*skip = 0;
	j = i + 1;
	while (is_valid_dollar_char(input[j]))
		j++;
	key = ft_substr(input, i + 1, j - i - 1);
	tmp = getvar(key, vars);
	if (tmp != NULL)
		val = ft_strdup(tmp);
	else
		val = ft_strdup("");
	free(key);
	*skip = j - i - 1;
	return (val);
}

static int	update_quote_state(char **input, int *p, char c, t_quote *quote)
{
	if (c == '\"')
	{
		if (*quote == none)
			*quote = dbl;
		else if (*quote == dbl)
			*quote = none;
		else
			*input[(*p)++] = '"';
		return (true);
	}
	else if (c == '\'')
	{
		if (*quote == none)
			*quote = single;
		else if (*quote == single)
			*quote = none;
		else
			*input[(*p)++] = '\'';
		return (true);
	}
	return (false);
}

static int expand_$(char *input, char *str, int *i, int *p, t_quote *quote, t_shellvar *vars)
{
	int		skip;
	char	*val;
	size_t	k;

	skip = 0;
	if (input[*i] == '$' && (*quote == none || *quote == dbl)
		&& (ft_isalpha(input[*i + 1]) || input[*i + 1] == '?' || input[*i
			+ 1] == '_' || !input[*i + 1]))
	{
		val = get_val(input, *i, &skip, vars);
		k = 0;
		while (k < ft_strlen(val))
			str[(*p)++] = val[k++];
		free(val);
		*i += skip;
		return (true);
	}
	else if (input[*i] == '$' && *quote == none && (input[*i + 1] == '\''
			|| input[*i + 1] == '"'))
		return (*i += 0,true);
	else if (input[*i] == '$' && ft_isdigit(input[*i + 1]))
		return (*i += 1,true);
	return (false);
}

char	*replace(char *input, t_shellvar *vars)
{
	t_quote	quote;
	char	*str;
	int		i;
	int		p;
	// int tab[2]; // i and p

	i = 0;
	p = 0;
	quote = none;
	str = malloc(sizeof(char) * (len_allocation(input, vars) + 1));
	while (input[i])
	{
		if (update_quote_state(&input, &p, input[i], &quote) == true)
			p += 0;
		else if (expand_$(input, str, &i, &p, &quote, vars) == true)
			p += 0;
		else
			str[p++] = input[i];
		i++;
	}
	str[p] = '\0';
	return (str);
}

// char	*replace(char *input, t_shellvar *vars)
// {
// 	t_quote	quote;
// 	int		i;
// 	char	*str;
// 	int		p;
// 	size_t	k;
// 	int		j;
// 	char	*key;
// 	char	*val;
// 	char	*tmp;

// 	quote = none;
// 	str = malloc(sizeof(char *) * (len_allocation(input,vars) + 1));
// 	p = 0;
// 	i = 0;
// 	k = 0;
// 	while (input[i])
// 	{
// 		// determining qoutes context
// 		if (input[i] == '\"')
// 		{
// 			if (quote == none)
// 				quote = dbl;
// 			else if (quote == dbl)
// 				quote = none;
// 			else
// 				str[p++] = '"';
// 		}
// 		else if (input[i] == '\'')
// 		{
// 			if (quote == none)
// 				quote = single;
// 			else if (quote == single)
// 				quote = none;
// 			else
// 				str[p++] = '\'';
// 		}
// 		// if $ and in replace mode do replace
// 		else if (input[i] == '$' && (quote == none || quote == dbl)
// 			&& (ft_isalpha(input[i + 1]) || input[i + 1] == '?' || input[i
// 				+ 1] == '_' || !input[i + 1]))
// 		{
// 			j = i + 1;
// 			// from $ to before first non valid char
// 			while (ft_isalpha(input[j]) || input[j] == '_'
// 				|| ft_isdigit(input[j]) || input[j] == '?')
// 				j++;
// 			key = ft_substr(input, i + 1, j - i - 1);
// 			tmp = getvar(key, vars);
// 			if (tmp != NULL)
// 				val = ft_strdup(tmp);
// 			else
// 				val = ft_strdup("");
// 			k = 0;
// 			while (k < ft_strlen(val))
// 				str[p++] = val[k++];
// 			i += j - i - 1;
// 			free(key);
// 			free(val);
// 		}
// 		// hard coded: $'USER' -> USER (no $)
// 		else if (input[i] == '$' && quote == none && (input[i + 1] == '\''
// 				|| input[i + 1] == '"'))
// 			i += 0;
// 		else if (input[i] == '$' && ft_isdigit(input[i + 1]))
// 			i += 1;
// 		else
// 			str[p++] = input[i];
// 		i++;
// 	}
// 	str[p] = '\0';
// 	return (str);
// }
