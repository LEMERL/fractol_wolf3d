/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frct_calculus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 15:44:45 by mgrimald          #+#    #+#             */
/*   Updated: 2015/02/25 19:46:15 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	rgb(int r, int g, int b)
{
	return (((r * 255) + g) * 255 + b);
}

int	color(double pos)
{
	int		hex;
	double	p;
	double	fpart;
	int		a;

	if (pos > 1.0)
		pos = (pos - (int)pos) == 0.0 ? 1.0 : (pos - (int)pos);
	p = 6 * pos;
	fpart = p - (int)p;
	a = (int)(fpart * 255);
	if ((int)p == 0)
		hex = rgb(0, a, 0);
	else if ((int)p == 1)
		hex = rgb(255 - a, 255, 0);
	else if ((int)p == 2)
		hex = rgb(0, 255, a);
	else if ((int)p == 3)
		hex = rgb(a, 255 - a, 255);
	else if ((int)p == 4)
		hex = rgb(a, 0, 255);
	else if ((int)p == 5)
		hex = rgb(0, 0, 255 - a);
	else
		hex = rgb(0, 0, 0);
	return (hex);
}

int	mandel(t_env *e, int x, int y)
{
	int		i;
	t_comp	z;
	t_comp	next;
	t_comp	c;

	c.real = e->x_min + (x / e->zoom);
	c.cplx = e->y_min + (y / e->zoom);
	z.real = e->cst.real;
	z.cplx = e->cst.cplx;
	i = 0;
	while (i < e->iter_max && z.real * z.real + z.cplx * z.cplx < 4)
	{
		next.real = (z.real * z.real) - (z.cplx * z.cplx) + c.real;
		next.cplx = 2 * z.real * z.cplx + c.cplx;
		z = next;
		i++;
	}
	mlxr_pixel_put_img(e, x, y, color((double)i / (double)e->iter_max));
	if ((e->x_min + (x / e->zoom) >= -0.01 && e->x_min + (x / e->zoom) <= 0.01) || (e->y_min + (y / e->zoom) >= -0.01 && e->y_min + (y / e->zoom) <= 0.01))
		mlxr_pixel_put_img(e, x, y, 0xFF0000);
	return (0);
}