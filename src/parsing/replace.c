#include "../main.h"

t_quote	update_quote(char c, t_quote current)
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

char	*replace(char *input, t_shellvar *vars)
{
	t_quote	quote;
	int		i;
	int		str_len;
	char	*str;
	int		p;
	size_t	k;
	int		j;
	char	*key;
	char	*val;
	char	*tmp;

	quote = none;
	i = 0;
	str_len = 0;
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
	str = malloc(sizeof(char *) * (str_len + 1));
	p = 0;
	i = 0;
	k = 0;
	while (input[i])
	{
		// determining qoutes context
		if (input[i] == '\"')
		{
			if (quote == none)
				quote = dbl;
			else if (quote == dbl)
				quote = none;
			else
				str[p++] = '"';
		}
		else if (input[i] == '\'')
		{
			if (quote == none)
				quote = single;
			else if (quote == single)
				quote = none;
			else
				str[p++] = '\'';
		}
		// if $ and in replace mode do replace
		else if (input[i] == '$' && (quote == none || quote == dbl)
			&& (ft_isalpha(input[i + 1]) || input[i + 1] == '?' || input[i
				+ 1] == '_' || !input[i + 1]))
		{
			j = i + 1;
			// from $ to before first non valid char
			while (ft_isalpha(input[j]) || input[j] == '_'
				|| ft_isdigit(input[j]) || input[j] == '?')
				j++;
			key = ft_substr(input, i + 1, j - i - 1);
			tmp = getvar(key, vars);
			if (tmp != NULL)
				val = ft_strdup(tmp);
			else
				val = ft_strdup("");
			k = 0;
			while (k < ft_strlen(val))
				str[p++] = val[k++];
			i += j - i - 1;
			free(key);
			free(val);
		}
		// hard coded: $'USER' -> USER (no $)
		else if (input[i] == '$' && quote == none && (input[i + 1] == '\''
				|| input[i + 1] == '"'))
			i += 0;
		else if (input[i] == '$' && ft_isdigit(input[i + 1]))
			i += 1;
		else
			str[p++] = input[i];
		i++;
	}
	str[p] = '\0';
	return (str);
}
