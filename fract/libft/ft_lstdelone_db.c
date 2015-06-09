/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_db.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 14:00:16 by mgrimald          #+#    #+#             */
/*   Updated: 2015/03/07 18:30:19 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone_db(t_lst_db **alst, void (*del)(void*, size_t))
{
	t_lst_db	*tmp;

	tmp = NULL;
	if (alst && *alst)
	{
		if ((*alst)->prev || (*alst)->next)
		{
			if ((*alst)->prev)
			{
				((*alst)->prev)->next = (*alst)->next;
				tmp = (*alst)->prev;
			}
			if ((*alst)->next)
			{
				((*alst)->next)->prev = (*alst)->prev;
				tmp = (*alst)->next;
			}
		}
		if (del)
			del((*alst)->content, (*alst)->content_size);
		(*alst)->content = NULL;
		free(*alst);
		*alst = tmp;
	}
}
