/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 16:06:13 by mgrimald          #+#    #+#             */
/*   Updated: 2015/02/25 17:16:30 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# include "libft/includes/libft.h"

typedef enum	e_select
{
	MANDELBROT,
	JULIA,
	OTHER,
}				t_select;

typedef struct	s_img
{
	void		*ptr;
	int			width;
	int			height;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_win
{
	void		*ptr;
	int			width;
	int			height;
}				t_win;

typedef struct	s_comp
{
	double		real;
	double		cplx;
}				t_comp;

typedef struct	s_env
{
	void		*mlx;
	t_win		*win;
	t_img		*img;
	t_select	slc;
	int			iter_max;
	int			mouse_x;
	int			mouse_y;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double		zoom;//float ?
	int			focus;
	t_comp		cst;
	int			restart;
}				t_env;

void			mlxr_new_img(t_env *env);
int				mlxr_pixel_put_img(t_env *e, int x, int y, int color);

void			frct_mlx(t_env *env);
void			frct_argument(t_env *env, int argc, char **argv);
void			frct_init(t_env *e);

void			frct_draw(t_env *e);
int				mandel(t_env *e, int x, int y);

void			ft_fatal_error(t_env *env);

#endif
