/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 18:52:45 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/08/20 19:56:10 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

/*
 * fixe la valeur de compare needed! il me sort une valeur de merde
 */

static int		find_short_link(t_list *list, int nb)
{
	int			ret;
	t_list		*link;
	t_salle		*path;

	nb = 0;// il faut que je lui passe en param le nb de chemin que je eux
	ret = -1;
	link = list;
	while (((t_salle*)link->content)->status != END)
		link = link->next;
	path = ((t_salle *)list->content);
	link = path->link;
	while (path->way_value != nb)
	{
		if (((t_salle *)list->content)->way_value != nb)
		{
			path = ((t_salle *)list->content);
			link = path->link;
		}
		link = link->next;
	}
		printf ("compare = [%d], name = [%s], dist = [%d]\n", ret, ((t_salle *)link->content)->name, ((t_salle *)link->content)->dist);
	while (link != NULL)
	{
		printf ("name = [%s], dist = [%d]\n", ((t_salle *)link->content)->name, ((t_salle *)link->content)->dist);
		if (ret == -1 || ret < ((t_salle *)link->content)->dist)
			ret = ((t_salle *)link->content)->dist;
		printf ("compare = [%d], name = [%s], dist = [%d]\n", ret, ((t_salle *)link->content)->name, ((t_salle *)link->content)->dist);
		link = link->next;
	}
	return (ret);
}

static void		find_room(t_salle *path, int value, int compare, t_list *list)
{
	t_list			*link;

	link = path->link;
	while (link != NULL || ((t_salle *)link->content)->dist == compare)
	{
	//	ft_putstr(((t_salle *)link->content)->name);
	//	printf ("compare = [%d], name = [%s], dist = [%d]\n", compare, ((t_salle *)link->content)->name, ((t_salle *)link->content)->dist);
	//	ft_putstr("\n");
		link = link->next;
		if (link == NULL)
			break;
	}
	exit (0);
	ft_putstr("la bouboub");
	path = ((t_salle *)link->content);
	path->way_value = value;
}

void			find_all_path(t_list *list, const int value)
{
	t_salle			*path;
	t_list			*link;
	int				compare;
	int nb = 0;//lui passer le nombre de chemin desire

	link = list;
	while (((t_salle *)link->content)->status != END)
		link = link->next;
	path = ((t_salle *)link->content);
	while (path->status != START)
	{
		link = path->link;
		compare = find_short_link(list, nb);
		find_room(path, value, compare, list);
	}
}
