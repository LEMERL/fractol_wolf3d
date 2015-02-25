/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 14:39:41 by mgrimald          #+#    #+#             */
/*   Updated: 2015/02/24 19:24:38 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>
int		main(int argc, char **argv)
{
	int			x;
	int			y;
	t_struct	***tab;

	x = -1;
	if (argc == 2)
		tab = wlf_get_tab(*(argv + 1));
	while (((y = -1) + 2) && tab && tab[++x])
	{
		while (tab[x][++y])
			printf("x : %d\t%d\ny : %d\t%d\nz = %d\n\n", x, tab[x][y]->x, y, tab[x][y]->y, tab[x][y]->z);
	}
	return (0);
}
