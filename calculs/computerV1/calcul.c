/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 15:42:09 by mgrimald          #+#    #+#             */
/*   Updated: 2015/03/27 14:29:01 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap/libft/includes/libft.h"

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
}

double		squre_root(double x)
{
	double	v;
	double	y;
	double	z;
	int	cont;

	z = 0.0;
	cont = 4;
	v = 0.0;
	while (cont && x >= 0)
	{
		z = z + v;
		if (v == 0.0)
			v = 1.0;
		y = z * z;
		if (y == x)
			return (z);
		while (cont && (z + v) * (z + v) > x)
		{
			v = v / 10;
			cont--;
		}
	}
	return (z);
}

void	poly_sec(t_num a, t_num b, t_num c)
{
	t_num		delta;

	delta = b * b - 4 * a * c;
	if (delta > 0)
	{
		ft_putstr("les differentes valeurs de x possibles sont :\n");
	}
	if (delta == 0)
		ft_putstr("a solution avaible\n");
	if (delta < 0)
		ft_putstr("no solution avaible\n");
}
