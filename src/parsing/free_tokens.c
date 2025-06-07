#include "../main.h"


void free_tokens(t_token *tks)
{
	t_token *tmp ;

	while (tks)
	{
		tmp = tks->next;
		if (tks->value)
			free(tks->value);
		free(tks);
		tks = tmp;
	}
}