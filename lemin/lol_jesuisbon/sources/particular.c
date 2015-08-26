/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   particular.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 02:18:40 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/08/26 17:18:26 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int		*ret_array(int nb, int path_length, int how_many, int rec)
{
	int			*ret;
	int			temp;

	ret = (int *)malloc(sizeof(int) * how_many);
	temp = 1;
	ret[0] = nb + rec;
	while (temp < how_many)
	{
		ret[temp] = nb;
		temp++;
	}
	return (ret);
}

static void		add_in_start(t_list *list)
{
	((t_salle *)list->content)->indice = 1;
}

/*static void		print_special_norme(int *ant, t_list *list, int tot)
{
	t_list		*link;
	int			i;
	int			count;
	int			ant_v;

	printf ("print_special");
	link = list;
	while (((t_salle *)link->content)->status != END)
		link = link->next;
	ant_v = 1;
	add_in_start(list);
	while (tot >= 0)
	{
		i = 0;
		count = 0;
		while (ant[i])
		{
			if (ant[i] >= 0)
			{
				add_in_start(list);
				iter_path(link, i + 1, ant_v);
				ant[i] -= 1;
				count++;
			}
			if (ant[i] == 0 && ant[0] != 0)
			{
				while (ant[0] >= 0)
				{
					iter_path(link, 1, ant_v);
					ant[0] = ant[0] - 1;
					count++;
				}
			}
			i++;
			ant_v++;
		}
		ft_putchar('\n');
		tot = tot - count;
	}
	printf ("end\n");
}*/

//add une fourmi a start la fait avancer avec indice == name fourmi
// while tab[i] repeat et move avec indice qui a la valuer de la fourmi
// fonction avancer + repeat_add

void			print_special_norme(int *ant, t_list *list, int tot)
{
	t_list		*link;
	int			i;
	int			count;
	int			ant_v;

	link = list;
	while (((t_salle *)link->content)->status != END)
		link = link->next;
	ant_v = 1;
	while (tot >= 0)
	{
		i = 0;
		count = 0;
		while (ant[i])
		{
			if (ant[i] > 0)
			{
				add_in_start(list);
				iter_path(link, i + 1, ant_v);
				ant[i] -= -1;
				count++;
			}
			i++;
			ant_v++;
		}
		ft_putchar('\n');
		tot = tot - count;
	}
}

static void		reinit_indice(t_list *list)
{
	t_list			*link;

	link = list;
	while (link != NULL)
	{
		((t_salle *)link->content)->indice = 0;
		link = link->next;
	}
}

static void		print_special(int *ant, t_list *list)
{
	int			tot;
	int			i;

	i = 0;
	tot = 0;
	while (ant[i])
	{
		tot = tot + ant[i];
		i++;
	}
	reinit_indice(list);
	print_special_norme(ant, list, tot);
}

static void		group_ant(int path_length, int ant,
		int how_many, t_list *list)
{
	float			parse;
	float			rec;
	int				*ret;

	ret = (int *)malloc(sizeof(int) * how_many);
	rec = 0;
	parse = ant / how_many;
	if (parse - (int)parse != 0)
	{
		rec = parse - (int)parse;
		rec = rec * how_many;
		rec++;
		rec = rec - (rec - (int)rec);
	}
	parse = parse - (parse - (int)parse);
	ret = ret_array((int)parse, path_length, how_many, (int)rec);
	print_special(ret, list);
//	exit(0);
}

void			particular(int *possible, int i, int ant, t_list *list)
{
	int			temp;
	int			cmp;

	temp = i - 1;
	cmp = possible[0];
	printf ("temp = %d", temp);
	while (temp > 0)
	{
		if (cmp != possible[temp])
		{
			printf ("rett");
			return ;
		}
		temp--;
	}
	printf ("teist end\n");
	group_ant(possible[0], ant, i, list);
}
