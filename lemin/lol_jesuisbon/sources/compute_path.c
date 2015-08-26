/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 01:53:58 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/08/26 16:23:46 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int		compute_path(int nb, int path)
{
	float			ret;

	ret = (nb - path) / 2;
	if (ret - (int)ret != 0)
		ret++;
	return ((int)ret);
}

void			compute_way(int ant, int *every_path, int len)
{
	int			nb;
	int			*print;
	int			i;

	i = 1;
	//printf ("len = %d\n", len);
	print = (int *)malloc(sizeof(int) * len);
	nb = ant + every_path[0] - 1;
	print[0] = nb;
	printf ("nombre de coups [%d],\n print[%d]\n", nb, print[0]);
	while (i <= len)
	{
		if (nb > every_path[i])
		{
			print[i] = compute_path(nb, every_path[i]);
			nb = print[i];
			printf ("print[%d] == %d\n", i, print[i]);
		}
		i++;
	}
}
