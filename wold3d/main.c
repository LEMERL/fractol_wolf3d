/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 14:39:41 by mgrimald          #+#    #+#             */
/*   Updated: 2015/02/28 17:07:05 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

int		wolf2d_mlx(t_env *env);

int		put_square(t_img *img, int x, int y, int color)
{
	int		tmp_x;
	int		tmp_y;
	int		square;

	square = 20;
	tmp_x = - 1;
	while ((++tmp_x) < square)
	{
		tmp_y = - 1;
		while ((++tmp_y) < square)
		{
			mlxr_pixel_put_img(img, x * square + tmp_x, y * square + tmp_y, color);
		}
	}
	return (1);
}

int		player(t_env *e)
{
	e->player.width = 20;
	e->player.height = 20;
	e->player.x = 30;
	e->player.y = 30;
	e->player.img = mlxr_new_img(e, e->player.width, e->player.height);
	put_square(e->player.img, 0, 0, 0x0000FF);
	mlx_put_image_to_window(e->mlx, e->win, e->player.img->ptr, e->player.x, e->player.y);
	return (1);
}

int		main(int argc, char **argv)
{
	t_env	env;
	int			x;
	int			y;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 600, 600, "wolf_2d");
	env.img = mlxr_new_img(&env, 600, 600);
	x = -1;
	env.tab = NULL;
	if (argc == 2)
		env.tab = wlf_get_tab(*(argv + 1));
	if (env.tab == NULL)
		return (-1);
	while (((y = -1) + 2) && env.tab && env.tab[++x])
	{
		while (env.tab[x][++y])
		{
//	printf("x : %d\t%d\ny : %d\t%d\nz = %d\n\n", x, env.tab[x][y]->x, y, env.tab[x][y]->y, env.tab[x][y]->z);
			if (env.tab[x][y]->z == 0)
				put_square(env.img, x, y, 0x00FF00);
			else
				put_square(env.img, x, y, 0xFF0000);
		}
	}
	mlx_put_image_to_window(env.mlx, env.win, env.img->ptr, 0, 0);
	player(&env);
	wolf2d_mlx(&env);
	return (0);
}
