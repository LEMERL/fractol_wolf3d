/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 18:52:45 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/08/21 14:46:25 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

/*
 * fixe la valeur de compare needed! il me sort une valeur de merde
 * find_short_link ne trouve pas le plus court
 */

static int		find_short_link(t_list *list, int nb)
{
	int			ret;
	t_list		*link;
	t_salle		*path;

	nb = 0;
	ret = -1;
	link = list;
	while (((t_salle*)link->content)->status != END)
	{
		link = link->next;
	}
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
	while (link != NULL)
	{
		if ((ret == -1 || ret < ((t_salle *)link->content)->dist) && ((t_salle *)link->content)->way_value == 0)
		{
			ret = ((t_salle *)link->content)->dist;
		}
		link = link->next;
	}
	return (ret);
}

static t_salle	*find_room(t_salle *path, int value, int way_value, t_list *list)
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
	printf ("\nXDLOL : name = [%s], path->dist [%d], \n", path->name, path->dist );
	i--;
	return (path);
}

static int		path_exist(t_list *link, int way)
{
	while (link != NULL && ((t_salle *)link->content)->status != START)
	{
		if (((t_salle *)link->content)->way_value == way)
		{
			printf ("je ret 0");
			return (0);
		}
		link = link->next;
	}
	printf ("je ret 1");
	return (1);
}

static t_list		*follow_the_good_way(t_list *list, int way)
{
	t_list			*link;
	t_salle			*path;

	link = list;
	while (((t_salle *)link->content)->status != END)
		link = link->next;
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
			{
				link = link->next;
			}
			if (link->next != NULL)
				link = link->next;
		}
		return (link);
	}
	else
		return (list);
}

void			find_all_path(t_list *list, const int value)
{int way = 1;int i = 0;
	t_salle			*path;
	t_list			*link;
	int				compare;
	int nb = 0;

	link = list;
	while (((t_salle *)link->content)->status != END)
		link = link->next;
	path = ((t_salle *)link->content);
	link = path->link;
	compare = find_short_link(list, nb);
	while (path->status != START)
	{
		path = find_room(path, value, compare , list);
		link = follow_the_good_way(list, way);
	}
}
