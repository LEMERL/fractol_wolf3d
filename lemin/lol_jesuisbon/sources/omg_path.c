/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   omg_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 03:37:27 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/08/24 03:39:12 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

#define CNT ((t_salle *)link->content)

static t_salle	*is_path(t_salle *salle, int value)
{
	int			ret;
	t_list		*link;
	t_salle		*temp;

	link = salle->link;
	ret = -1;
	salle->way_value = value;
	temp = NULL;
	while (link != NULL)
	{
		if ((ret == -1 && CNT->way_value == 0) || (ret > (CNT)->dist &&
					CNT->way_value == 0))
		{
			temp = CNT;
			ret = (CNT)->dist;
		}
		link = link->next;
	}
	return (temp);
}

static int		path_avaiable(t_list *list)
{
	t_salle		*path;
	t_list		*l;
	int			i;

	i = 0;
	path = ((t_salle *)list->content);
	l = path->link;
	while (l != NULL)
	{
		if (((t_salle *)l->content)->way_value == 0)
			i++;
		l = l->next;
	}
	return (i);
}

static int		how_many_valid(t_list *list)
{
	int		i;
	t_list	*link;
	t_salle	*path;

	link = list;
	path = CNT;
	link = path->link;
	i = 0;
	while (link != NULL)
	{
		if (((t_salle *)link->content)->way_value != 0)
			i++;
		link = link->next;
	}
	return (i);
}

void			omg(t_list *list, int value, int ant)
{
	t_list		*link;
	t_salle		*path;
	t_list		*start;
	static int	o = 0;

	value = 1;
	link = list;
	start = list;
	while (((t_salle *)link->content)->status != END)
		link = link->next;
	path = CNT;
	while (path_avaiable(link) >= 1)
	{
		while (path && path->status != START)
		{
			path = is_path(path, value);
		}
		reinit_dist(start);
		give_value((t_salle*)start->content);
		((t_salle *)list->content)->dist = 0;
		value++;
		path = ((t_salle *)link->content);
	}
	print(list, how_many_valid(list), ant);
	exit(0);
}
