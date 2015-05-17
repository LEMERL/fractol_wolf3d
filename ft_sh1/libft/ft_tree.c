/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 13:51:35 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/16 15:15:58 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tree	*ft_treenew(void const *content, size_t size, int value)
{
	t_tree	*new;
	void	*ptr;

	new = NULL;
	if ((new = (t_tree*)ft_strnew(sizeof(t_tree) - 1)) == NULL)
		return (NULL);
	new->content = NULL;
	new->size = 0;
	if (size == 0 && content != NULL)
		size = ft_strlen(content);
	if (content != NULL)
	{
		ptr = NULL;
		if ((ptr = (void*)ft_strnew(size)) == NULL)
			return (NULL);
		ft_memcpy(ptr, content, size);
		new->content = ptr;
		new->size = size;
	}
	new->right = NULL;
	new->left = NULL;
	return (new);
}

void	ft_treeadd(t_tree **atree, t_tree *nw)
{
	t_tree	*tree;
	t_tree	*tmp;

	tree = *atree;
	while (tree && nw->value != tree->value)
	{
		tmp = tree;
		if (nw->value == tree->value)
		{
			
			break ;
		}
		else if (nw->value > tree->value)
			tree = tree->right;
		else if (nw->value < tree->value)
			tree = tree->left;
	}
	if ()
		nw->next = *atree;
}

void	ft_treeaddnew(t_tree **atree, void *content, size_t size, int value)
{
	t_tree	*nw;

	nw = ft_treenew(content, size, value);
	if (atree && *atree == NULL && nw)
		*atree = nw;
	ft_treeadd(atree, nw);
}
