/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 18:54:30 by mgrimald          #+#    #+#             */
/*   Updated: 2015/03/11 18:57:15 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_lst	*sw_lstnew(t_lst *lst, int i)
{
	t_lst		*new;

	if ((new = malloc(sizeof(t_lst))))
		ft_error("sw_lstnew", 'm');
	new->data = i;
	new->next = NULL;
	new->prev = NULL;
	if (lst != NULL)
	{
		new->next = lst;
		new->prev = lst->prev;
		if (lst->prev != NULL)
			lst->prev = new;
	}
	lst = new;
	return (new);
}

t_lst	*sw_lstdelone(t_lst *alst)
{
	t_lst	*tmp;

	tmp = NULL;
	if (alst)
	{
		tmp = alst->prev;
		if (alst->prev)
			alst->prev->next = alst->next;
		if (alst->next)
		{
			alst->next->prev = alst->prev;
			tmp = alst->next;
		}
		free(alst);
	}
	return (tmp);
}

void	sw_lstdelall(t_lst **alst)
{
	while ((*alst)->prev)
		*alst = (*alst)->prev;
	while (alst && *alst)
		*alst = sw_lstdelone(*alst);
}
