/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 16:45:51 by mgrimald          #+#    #+#             */
/*   Updated: 2015/07/31 16:28:14 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	frct_draw(t_env *e)
{
	int		x;
	int		y;

	if (e->iter_max <= 0)
		e->iter_max = 10;
	e->min.real = e->centre.real - ((e->win->width / 2) * e->zoom);
	e->min.cplx = e->centre.cplx - ((e->win->height / 2) * e->zoom);
	e->max.real = e->centre.real + ((e->win->width / 2) * e->zoom);
	e->max.cplx = e->centre.cplx + ((e->win->height / 2) * e->zoom);
	x = -1;
	mlx_clear_window(e->mlx, e->win->ptr);
	while (++x < e->img->width)
	{
		y = -1;
		while (++y < e->img->height)
		{
			if (e->slc == MANDELBROT || e->slc == JULIA)
				mandel(e, x, y);
			else
				other_fract(e, x, y);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win->ptr, e->img->ptr, 0, 0);
}
