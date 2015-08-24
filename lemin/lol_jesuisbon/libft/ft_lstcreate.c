/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 19:38:26 by mgrimald          #+#    #+#             */
/*   Updated: 2015/08/12 19:48:24 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcreate(void *content)
{
	t_list	*new_list;

	if ((new_list = (t_list*)ft_strnew(sizeof(t_list) - 1)) == NULL)
	{
		return (NULL);
	}
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}

t_list	*ft_lstaddcreate(t_list **alst, void *content)
{
	t_list	*new_list;

	if ((new_list = ft_lstcreate(content)) == NULL)
		return (NULL);
	if (alst && *alst)
		new_list->next = *alst;
	*alst = new_list;
	return (*alst);
}
