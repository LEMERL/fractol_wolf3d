/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 16:45:51 by mgrimald          #+#    #+#             */
/*   Updated: 2015/02/25 20:38:37 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	frct_draw(t_env *e)
{
	int		x;
	int		y;

	e->zoom = e->win->height / (e->x_max - e->x_min);
	x = -1;
	mlx_clear_window(e->mlx, e->win->ptr);
	while (++x < e->img->width)
	{
		y = -1;
		while (++y < e->img->height)
		{
			if (e->slc == MANDELBROT || e->slc == JULIA)
				mandel(e, x, y);
			if (e->slc == OTHER)
				mandel(e, x, y);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win->ptr, e->img->ptr, 0, 0);
}
