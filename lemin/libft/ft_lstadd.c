/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 11:25:40 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/16 14:14:01 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *nw)
{
	if (alst && nw)
	{
		nw->next = *alst;
		*alst = nw;
	}
}

void	ft_lstaddnew(t_list **alst, void *content, size_t size)
{
	t_list	*nw;

	nw = ft_lstnew(content, size);
	if (alst && *alst == NULL && nw)
		*alst = nw;
	else if (alst && nw)
	{
		nw->next = *alst;
		*alst = nw;
	}
}
