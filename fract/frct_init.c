/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frct_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 13:31:03 by mgrimald          #+#    #+#             */
/*   Updated: 2015/07/31 16:34:15 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	frct_argument(t_env *env, int argc, char **argv)
{
	if (argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
		env->slc = MANDELBROT;
	else if (argc == 2 && ft_strcmp(argv[1], "julia") == 0)
		env->slc = JULIA;
	else if (argc == 2 && ft_strcmp(argv[1], "ternaire") == 0)
		env->slc = MANDEL_3;
	else if (argc == 2 && ft_strcmp(argv[1], "another") == 0)
		env->slc = JUL_3;
	else
	{
		ft_putendl_fd("parameter(s) invalid.\nList of valid parameters :", 2);
		ft_putendl_fd("\t\tmandelbrot", 2);
		ft_putendl_fd("\t\tjulia", 2);
		ft_putendl_fd("\t\tternaire", 2);
		ft_putendl_fd("\t\tanother", 2);
		exit(0);
	}
}

void	frct_init(t_env *e, int n)
{
	void	*win;
	void	*mlx;
	void	*img;

	img = e->img;
	win = e->win;
	mlx = e->mlx;
	if (n == -1)
		n = e->slc;
	ft_bzero(e, sizeof(t_env));
	e->mlx = mlx;
	e->win = win;
	e->img = img;
	e->zoom = 0.003;
	e->centre.real = 0.0;
	if (n == MANDELBROT)
		e->centre.real = -0.85;
	e->centre.cplx = 0.0;
	e->iter_max = 50;
	e->cst.real = 0.0;
	e->cst.cplx = 0.0;
	e->focus = 0;
	if ((e->slc = n) == JULIA)
		e->focus = 1;
	mlxr_new_img(e);
}
