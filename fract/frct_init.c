/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frct_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 13:31:03 by mgrimald          #+#    #+#             */
/*   Updated: 2015/07/31 19:39:08 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	frct_argument(t_env *env, int argc, char **argv)
{
	if (argc >= 2 && (!ft_strcmp(argv[argc - 1], "mandelbrot")
			|| !ft_strcmp(argv[argc - 1], "perpandicular")))
		env->slc = MANDELBROT;
	else if (argc >= 2 && (!ft_strcmp(argv[argc - 1], "julia")
			|| !ft_strcmp(argv[argc - 1], "style")))
		env->slc = JULIA;
	else if (argc >= 2 && (!ft_strcmp(argv[argc - 1], "ternaire")
			|| !ft_strcmp(argv[argc - 1], "bird")))
		env->slc = MANDEL_3;
	else if (argc >= 2 && (!ft_strcmp(argv[argc - 1], "another")
			|| !ft_strcmp(argv[argc - 1], "last")))
		env->slc = JUL_3;
	else
	{
		ft_putendl_fd("parameter(s) invalid.\nList of valid parameters :", 2);
		ft_putendl_fd("(depending on compilation mode)", 2);
		ft_putendl_fd("\t\tmandelbrot\tor\tperpandicular", 2);
		ft_putendl_fd("\t\tjulia\t\tor\tstyle", 2);
		ft_putendl_fd("\t\tbird\t\tor\tternaire", 2);
		ft_putendl_fd("\t\tanother\t\tor\tlast", 2);
		ft_fatal_error(env);
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
