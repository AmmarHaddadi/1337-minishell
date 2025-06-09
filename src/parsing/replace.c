#include "../main.h"

char *replace(char *input, t_shellvar *vars) {
	t_quote quote = none;
	int i = 0;
	int str_len = 0;

	while (input[i]) {
		// determining qoutes context
		if (input[i] == '\"') {
			if (quote == none)
				quote = dbl;
			else if (quote == dbl)
				quote = none;
			else
				str_len++;
		} else if (input[i] == '\'') {
			if (quote == none)
				quote = single;
			else if (quote == single)
				quote = none;
			else // commmenti hadi ida bghiti
				str_len++;
		}
		// if $ and in replace mode do replace
		else if (input[i] == '$' && (quote == none || quote == dbl) &&
				 (ft_isalpha(input[i + 1]) || input[i + 1] == '?' || input[i + 1] == '_' ||  !input[i + 1])) {
			int j = i + 1;
			// from $ to before first non valid char
			while (ft_isalpha(input[j]) || input[j] == '_' || ft_isdigit(input[j]) || input[j] == '?')
				j++;
			char *key = ft_substr(input, i + 1, j - i - 1);
			char *val = getvar(key, vars);
			if(getvar(key, vars) == NULL)
				val = ft_strdup("");
			str_len += ft_strlen(val);
			i += j - i - 1;
			free(key);
		}
		// hard coded: $'USER' -> USER (no $)
		else if (input[i] == '$' && quote == none && (input[i + 1] == '\'' || input[i + 1] == '"'))
			i += 0;
		else if( input[i] == '$' && ft_isdigit(input[i + 1]))
			i += 1;
		else
			str_len++;
		i++;
	}

	char *str = malloc(sizeof(char *) * ( str_len + 1));

	int p = 0;
	i = 0 ;
	size_t k = 0;
	while (input[i]) {
		// determining qoutes context
		if (input[i] == '\"') {
			if (quote == none)
				quote = dbl;
			else if (quote == dbl)
				quote = none;
			else
				str[p++] = '"';
		} else if (input[i] == '\'') {
			if (quote == none)
				quote = single;
			else if (quote == single)
				quote = none;
			else // commmenti hadi ida bghiti
				str[p++] = '\'';
		}
		// if $ and in replace mode do replace
		else if (input[i] == '$' && (quote == none || quote == dbl) &&
				 (ft_isalpha(input[i + 1]) || input[i + 1] == '?'  || input[i + 1] == '_' ||  !input[i + 1])) {
			int j = i + 1;
			// from $ to before first non valid char
			while (ft_isalpha(input[j]) || input[j] == '_' || ft_isdigit(input[j]) || input[j] == '?' )
				j++;
			char *key = ft_substr(input, i + 1, j - i - 1);
			char *val = getvar(key, vars);
			if(getvar(key, vars) == NULL)
				val = ft_strdup("");
			k = 0;
			while ( k < ft_strlen(val))
				str[p++] = val[k++];
			i += j - i - 1;
			free(key);
		}
		// hard coded: $'USER' -> USER (no $)
		else if (input[i] == '$' && quote == none && (input[i + 1] == '\'' || input[i + 1] == '"'))
			i += 0;
		else if( input[i] == '$' && ft_isdigit(input[i + 1]))
			i += 1;
		else
			str[p++] =  input[i];
		i++;
	}
	str[p] = '\0';

	return str;
}

