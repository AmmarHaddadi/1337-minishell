#include "../main.h"

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

static int	update_quote_state(char **input,int *p,char c, t_quote *quote)
{
	if (c == '\"')
	{
		if (*quote == none)
			*quote = dbl;
		else if (*quote == dbl)
			*quote = none;
        else
            *input[(*p)++] = '"';
         return(true);
	}
	else if (c == '\'')
	{
		if (*quote == none)
			*quote = single;
		else if (*quote == single)
			*quote = none;
        else
            *input[(*p)++] = '\'';
        return(true);
	}
        return(false);
}

char	*replace(char *input, t_shellvar *vars)
{
	t_quote	quote;
	char	*str;
	int		i = 0, p = 0, skip;
	char	*val;
    size_t k;

	quote = none;
	str = malloc(sizeof(char) * (len_allocation(input, vars) + 1));
	i = 0, p = 0, skip = 0;
	while (input[i])
	{
        if (update_quote_state(&input,&p,input[i], &quote) == true)
            p += 0;
		else if (input[i] == '$' && (quote == none || quote == dbl)
			&& (ft_isalpha(input[i + 1]) || input[i + 1] == '?' || input[i + 1] == '_' || !input[i + 1]))
		{
            skip = 0 ;
			val = get_val(input, i, &skip, vars);
            k = 0;
			while (k < ft_strlen(val))
				str[p++] = val[k++];
			free(val);
			i += skip;
		}
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
