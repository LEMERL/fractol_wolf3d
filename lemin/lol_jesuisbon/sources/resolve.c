/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 18:47:37 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/08/24 03:36:59 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		init_dist(t_list *list)
{
	t_list			*yolo;
	t_salle			*salle;

	yolo = list;
	salle = (t_salle *)yolo->content;
	while (yolo != NULL)
	{
		salle = (t_salle *)yolo->content;
		salle->dist = -1;
		salle->way_value = 0;
		salle->simple = 0;
		yolo = yolo->next;
	}
}

void			give_value(t_salle *salle)
{
	t_list		*link;
	t_salle		*test;
	t_list		*temp_link;

	link = salle->link;
	temp_link = link;
	while (link != NULL)
	{
		test = (t_salle *)link->content;
		if ((test->dist > salle->dist + 1 || test->dist == -1)
				&& test->way_value == 0)
		{
			test->dist = salle->dist + 1;
			if (test->status != END)
				give_value(test);
		}
		link = link->next;
	}
}

void			valid_start(t_list *list)
{
	t_list			*link;
	t_salle			*path;

	path = (t_salle *)list->content;
	link = path->link;
	if (path->link == NULL)
	{
		ft_putstr("no link around start\n");
		exit(0);
	}
}

static void		one_step(t_list *list, int ant)
{
	t_salle				*path;

	path = ((t_salle *)list->content);
	while (path->status != END)
	{
		list = list->next;
		path = (t_salle *)list->content;
	}
	if (path->dist == 1)
	{
		while (ant > 0)
		{
			ft_putstr("L");
			ft_putnbr(ant);
			ant--;
			ft_putstr("-");
			ft_putendl(path->name);
		}
		exit(0);
	}
}

void			resolve(t_list *list, int ant)
{
	int			petit;
	int			value;

	value = 1;
	init_dist(list);
	valid_start(list);
	((t_salle*)list->content)->dist = 0;
	give_value((t_salle*)list->content);
	one_step(list, ant);
	omg(list, value, ant);
}
