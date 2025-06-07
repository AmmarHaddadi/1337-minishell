/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:22:14 by ssallami          #+#    #+#             */
/*   Updated: 2025/06/07 16:46:13 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	ft_lstadd_back(t_token **lst, t_token *new)
{
	t_token	*prt;

	prt = *lst;
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (prt->next != NULL)
		prt = prt->next;
	prt->next = new;
}

void	ft_lstadd_back_cmd(t_command **lst, t_command *new)
{
	t_command	*prt;

	prt = *lst;
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (prt->next != NULL)
		prt = prt->next;
	prt->next = new;
}
void	ft_lstadd_back_redir(t_redir **lst, t_redir *new)
{
	t_redir *ptr;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ptr = *lst;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
}