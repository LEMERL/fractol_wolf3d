/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 17:07:38 by mgrimald          #+#    #+#             */
/*   Updated: 2015/01/22 21:49:23 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*ptr;

	new = NULL;
	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (ft_error("ft_lstnew", 'm'));
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		ptr = NULL;
		if ((ptr = (void*)malloc(content_size)) == NULL)
			return (ft_error("ft_lstnew", 'm'));
		ft_memcpy(ptr, content, content_size);
		new->content = ptr;
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
