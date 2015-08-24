/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 18:52:45 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/08/24 03:58:11 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

#define SLC ((t_salle *)link->content)

static int			find_short_link(t_list *list, int nb)
{
	static int	ret = -1;
	t_list		*link;
	t_salle		*path;

	nb = 0;
	link = list;
	while (((t_salle*)link->content)->status != END)
		link = link->next;
	path = ((t_salle *)link->content);
	link = path->link;
	while (link != NULL && path->way_value != nb)
	{
		if (((t_salle *)list->content)->way_value != nb)
		{
			path = ((t_salle *)list->content);
			link = path->link;
		}
		link = link->next;
	}
	return (find_short_link_norme(link, ret));
}

static t_salle		*find_room(t_salle *path, int value,
		int way_value, t_list *list)
{
	t_list			*link;
	static int		i = 0;

	link = path->link;
	path = ((t_salle *)link->content);
	way_value = 1;
	while (link != NULL && ((t_salle *)link->content)->dist == way_value)
	{
		link = link->next;
		if (link == NULL)
			return (path);
	}
	path = ((t_salle *)link->content);
	path->way_value = value;
	i--;
	return (path);
}

static int			path_exist(t_list *link, int way)
{
	while (link != NULL && ((t_salle *)link->content)->status != START)
	{
		if (((t_salle *)link->content)->way_value == way)
			return (0);
		link = link->next;
	}
	return (1);
}

static t_list		*follow_the_good_way(t_list *list, int way)
{
	t_list			*link;
	t_salle			*path;

	link = list;
	link = ret_end(link);
	path = ((t_salle *)link->content);
	link = path->link;
	if (link != NULL && path_exist(link, way) == 0)
	{
		while (link != NULL)
		{
			if (((t_salle *)link->content)->way_value == way)
			{
				path = ((t_salle *)link->content);
				link = path->link;
			}
			while (link != NULL && ((t_salle *)link->content)->way_value != way)
				link = link->next;
			if (link->next != NULL)
				link = link->next;
		}
		return (link);
	}
	else
		return (list);
}

void				find_all_path(t_list *list, const int value)
{
	int				way;
	t_salle			*path;
	t_list			*link;
	int				compare;
	int				nb;

	link = list;
	way = 1;
	nb = 1;
	while (((t_salle *)link->content)->status != END)
		link = link->next;
	path = ((t_salle *)link->content);
	link = path->link;
	compare = find_short_link(list, nb);
	while (path->status != START)
	{
		path = find_room(path, value, compare, list);
		link = follow_the_good_way(list, way);
	}
}
