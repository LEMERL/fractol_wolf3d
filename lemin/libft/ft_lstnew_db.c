/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_db.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 18:03:24 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/12 21:03:03 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst_db	*ft_lstnew_db(void const *cont, size_t cont_size)
{
	t_lst_db	*new;
	t_lst_db	*ptr;

	if ((new = (t_lst_db*)ft_strnew(sizeof(t_lst_db) - 1)) == NULL)
		return (NULL);
	if (cont == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		ptr = NULL;
		if ((ptr = (void*)ft_strnew(cont_size)) == NULL)
			return (NULL);
		ft_memcpy(ptr, cont, cont_size);
		new->content = ptr;
		new->content_size = cont_size;
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
