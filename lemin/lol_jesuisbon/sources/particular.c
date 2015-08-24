/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   particular.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 02:18:40 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/08/24 03:58:19 by aiwanesk         ###   ########.fr       */
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

static void		print_special_norme(int *ant, t_list *list, int tot)
{
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
	print_special_norme(ant, list, tot);
}

static void		group_ant(int path_length, int ant, int how_many, t_list *list)
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
	ret = ret_array((int)parse , path_length, how_many, (int)rec);
	print_special(ret, list);
	exit (0);
}

void			particular(int *possible, int i, int ant, t_list *list)
{
	int			temp;
	int			cmp;

	temp = i - 1;
	cmp = possible[0];
	while (temp > 0)
	{
		if (cmp != possible[temp])
			return ;
		temp--;
	}
	group_ant(possible[0], ant, i, list);
}
