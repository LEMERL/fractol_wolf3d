/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frct_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 14:04:54 by mgrimald          #+#    #+#             */
/*   Updated: 2015/08/05 14:51:28 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#include "ft_event.h"

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 4 && (e->iter_max += 5))
		e->zoom = e->zoom * 0.75;
	else if (button == 5 && (e->iter_max -= 5))
		e->zoom = e->zoom * 1.5;
	if (button == 2)
	{
		e->cst.real = e->min.real + x * e->zoom;
		e->cst.cplx = e->min.cplx + y * e->zoom;
	}
	if (button == 1)
		e->focus = e->focus ? 0 : 1;
	frct_draw(e);
	return (0);
}

int		motion_hook(int x, int y, t_env *e)
{
	if (x >= 0 && y >= 0 && y <= e->win->width && x <= e->win->height
			&& e->focus)
	{
		e->cst.real = e->min.real + x * e->zoom;
		e->cst.cplx = e->min.cplx + y * e->zoom;
		frct_draw(e);
	}
	return (0);
}

void	key_hook_f(int keycode, t_env *e)
{
	if (keycode == ARROW_LEFT)
		e->centre.real -= 45 * e->zoom;
	else if (keycode == ARROW_UP)
		e->centre.cplx -= 45 * e->zoom;
	else if (keycode == ARROW_RIGHT)
		e->centre.real += 45 * e->zoom;
	else if (keycode == ARROW_DOWN)
		e->centre.cplx += 45 * e->zoom;
	else if (keycode == 69)
		e->iter_max += 50;
	else if (keycode == 78)
		e->iter_max -= 50;
	else if (keycode == KEY_R)
		frct_init(e, -1);
	else if (keycode == KEY_J)
		frct_init(e, JULIA);
	else if (keycode == KEY_M)
		frct_init(e, MANDELBROT);
	else if (keycode == KEY_K)
		frct_init(e, JUL_3);
	else if (keycode == KEY_I)
		frct_init(e, MANDEL_3);
	else if (keycode == KEY_R)
		frct_init(e, -1);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESCAPE)
		ft_fatal_error(e);
	else if (keycode == 27)
		e->zoom = e->zoom * 1.5;
	else if (keycode == 24)
		e->zoom = e->zoom * 0.75;
	else if (keycode == KEY_J)
		frct_init(e, JULIA);
	else if (keycode == KEY_M)
		frct_init(e, MANDELBROT);
	else if (keycode == KEY_K)
		frct_init(e, JUL_3);
	else if (keycode == KEY_I)
		frct_init(e, MANDEL_3);
	else if (keycode == KEY_C)
		e->color = e->color ? 0 : 1;
	else if (keycode == KEY_Z)
		e->mult = e->mult * 10;
	else if (keycode == KEY_X)
		e->mult = e->mult / 10;
	else
		key_hook_f(keycode, e);
	frct_draw(e);
	return (0);
}

void	frct_mlx(t_env *env)
{
	mlx_hook(env->win->ptr, 6, (1L << 6), motion_hook, env);
	mlx_hook(env->win->ptr, KEYPRESS, PRESSMASK, key_hook, env);
	mlx_mouse_hook(env->win->ptr, mouse_hook, env);
	mlx_expose_hook(env->win->ptr, expose_hook, env);
	mlx_loop(env->mlx);
}
