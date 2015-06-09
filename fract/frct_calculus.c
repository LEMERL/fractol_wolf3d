/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frct_calculus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 15:44:45 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/09 18:13:59 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		rgb(int r, int g, int b)
{
	return (((r * 255) + g) * 255 + b);
}

int		color_1(double pos)
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

static t_comp	init_comp(t_env *e, t_comp *c, int x, int y)
{
	t_comp	z;
	t_comp	n;

	c->real = e->min.real + (x * e->zoom);
	c->cplx = e->min.cplx + (y * e->zoom);
	z.real = e->cst.real;
	z.cplx = e->cst.cplx;
	if (e->slc == JULIA)
	{
		n = z;
		z = *c;
		*c = n;
	}
	return (z);
}

void	mandel(t_env *e, int x, int y)
{
	int		i;
	t_comp	z;
	t_comp	next;
	t_comp	c;

	i = -1;
	z = init_comp(e, &c, x, y);
	while (++i < e->iter_max && z.real * z.real + z.cplx * z.cplx <= 4)
	{
		next.real = (z.real * z.real) - (z.cplx * z.cplx) + c.real;
		next.cplx = 2 * z.real * z.cplx + c.cplx;
		z = next;
	}
	if (e->color == 0)
		mlxr_pixel_put_img(e, x, y, color_1((double)i / (double)e->iter_max));
	else
		mlxr_pixel_put_img(e, x, y, color_1((double)i / (double)e->iter_max));
}
