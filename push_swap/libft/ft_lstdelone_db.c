/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_db.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 14:00:16 by mgrimald          #+#    #+#             */
/*   Updated: 2015/01/06 18:20:18 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone_db(t_lst_db **ast, void (*del)(void*, size_t))
{
	t_lst_db	*tmp;

	if (ast && *ast)
	{
		if ((*ast)->prev || (*ast)->next)
		{
			if ((*ast)->prev)
			{
				((*ast)->prev)->next = (*ast)->next;
				tmp = (*ast)->prev;
			}
			if ((*ast)->next)
			{
				((*ast)->next)->prev = (*ast)->prev;
				tmp = (*ast)->next;
			}
		}
		if (del)
			del((*ast)->content, (*ast)->content_size);
		(*ast)->content = NULL;
		free(*ast);
		*ast = tmp;
	}
}
