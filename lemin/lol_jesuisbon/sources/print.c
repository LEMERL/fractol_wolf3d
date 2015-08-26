/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 16:04:53 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/08/26 16:54:17 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	modif_ant_pos(t_list *list, int path_length, int ant_v)
{
	t_list			*link;
	t_list			*refresh;

	link = list;
	while (((t_salle *)link->content)->way_value != path_length)
		link = link->next;
	refresh = link;
	while (((t_salle *)link->content)->way_value != path_length)
		refresh = refresh->next;
	((t_salle *)refresh->content)->indice = 0;
	((t_salle *)refresh->content)->indice = 1;
	ft_putchar('L');
	ft_putnbr(ant_v);
	ft_putchar('-');
	ft_putstr(((t_salle *)link->content)->name);
	ft_putchar('\n');
}

int		someone_in(t_list *list)
{
	t_list		*link;

	link = list;
	while (link != NULL)
	{
		if (((t_salle *)link->content)->indice != 0)
			return (1);
		link = link->next;
	}
	return (0);
}

int		iter_path(t_list *list, int path_length, int ant_v)
{
	t_list		*link;
	t_salle		*path;
	int			ret;

	ret = 0;
	path = ((t_salle *)list->content);
	link = path->link;
	printf ("\ntest\n");
	while (path->status != START && (link = path->link) && someone_in(list) == 1)
	{
		printf ("uol\n");
		link = path->link;
		while (1)
		{
			if (link == NULL || link->content == NULL || ((t_salle *)link->content)->status == START)
				return (ret);
			if (((t_salle *)link->content)->way_value == path_length && ((t_salle *)link->content)->dist <= path->dist)
			{
				modif_ant_pos(link, path_length, ant_v);
				break ;
			}
			link = link->next;
			if (link == NULL || link->content == NULL || ((t_salle *)link->content)->status == START)
				return (0);
		}
		path = ((t_salle *)link->content);
		if (path->status == START)
			return (ret);
		ret++;
	}
	return (ret);
}

static int	follow_path(t_list *list, int path_length)
{
	t_list		*link;
	t_salle		*path;
	int			ret;

	ret = 0;
	path = ((t_salle *)list->content);
	link = path->link;
	while (path->status != END && (link = path->link))
	{
		printf ("\tpath->name:%s, dist:%d\n", path->name, path->dist);
		while (1)
		{
			if (link == NULL || link->content == NULL || ((t_salle *)link->content)->status == END)
				return (ret);
			if (((t_salle *)link->content)->way_value == path_length)
				printf ("\t\t link->name = %s, dist = %d, way_value = %d\n", ((t_salle *)link->content)->name, ((t_salle *)link->content)->dist, ((t_salle *)link->content)->way_value);
			if (((t_salle *)link->content)->way_value == path_length && ((t_salle *)link->content)->dist >= path->dist)
				break ;
			link = link->next;
			if (link == NULL || link->content == NULL || ((t_salle *)link->content)->status == END)
				return (0);
		}
		path = ((t_salle *)link->content);
		if (path->status == END)
			return (ret);
		ret++;
	}
	return (ret);
}

void		print(t_list *list, int path, int ant)
{
	int			*possible;
	int			i;
	int			temp_path;

	temp_path = 1;
	possible = (int *)malloc(sizeof(int) * path);
	i = 0;
	while (i < path)
	{
		possible[i] = follow_path(list, temp_path) + 1;
		temp_path++;
		printf ("possible[%d] = %d\n", i ,possible[i]);
		i++;
	}
	if (possible[0] == 0)
		ft_error();
	if (i > 1)
	{
		printf ("test");
		particular(possible, i, ant, list);
		exit (0);
	}
	compute_way(ant, possible, i);
}

//nb + fourmis + nb de case - 1 = nb de coups
// CMP par rapport au second chemin if sup taille de chemin (nb cps - 9) /2)
//
