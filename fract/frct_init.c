/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frct_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 13:31:03 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/08 14:27:30 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	frct_argument(t_env *env, int argc, char **argv)
{
	if (argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
		env->slc = MANDELBROT;
	else if (argc == 2 && ft_strcmp(argv[1], "julia") == 0)
		env->slc = JULIA;
	else if (argc == 2 && ft_strcmp(argv[1], "other") == 0)
		env->slc = OTHER;
	else
	{
		ft_putendl_fd("parameter(s) invalid.\nList of valid parameters :", 2);
		ft_putendl_fd("\t\tmandelbrot", 2);
		ft_putendl_fd("\t\tjulia", 2);
		ft_putendl_fd("\t\tother", 2);
		exit(0);
	}
}

void	frct_init(t_env *e)
{
	e->win = (t_win*)ft_strnew((sizeof(t_win)));
	e->mlx = mlx_init();
	if (e->mlx == NULL || e->win == NULL)
		ft_fatal_error(e);
	e->win->width = 1000;
	e->win->height = 1000;
	e->win->ptr = mlx_new_window(e->mlx, e->win->width, e->win->height, "frct");
	if (e->win->ptr == NULL)
		ft_fatal_error(e);
	e->zoom = 0.004;
/*	e->min.real = -2.0;
	e->max.real = 1.0;
	e->min.cplx = -2.0;
	e->max.cplx = 1.0;*/
	e->centre.real = 0.0;
	e->centre.cplx = 0.0;
	e->iter_max = 200;
	e->cst.real = -1.0;
	e->cst.cplx = 0.0;
	if (e->slc == JULIA)
		e->focus = 1;
	else 
		e->focus = 0;
	mlxr_new_img(e);
}

