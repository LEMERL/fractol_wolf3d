/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frct_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 14:04:54 by mgrimald          #+#    #+#             */
/*   Updated: 2015/07/30 19:12:26 by mgrimald         ###   ########.fr       */
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
	printf("button: %d\n", button);
	printf("x: %d\ty%d\n", x, y);
	printf("center.real: %f\tcenter.cmplx: %f\n", e->centre.real, e->centre.cplx);
	printf("min.real: %f\tmax.real: %f\n", e->min.real, e->max.real);
	printf("min.cplx: %f\tmax.cplx: %f\n", e->min.real, e->max.real);
	printf("cst.real: %f\tcst.cplx: %f\n", e->cst.real, e->cst.cplx);
	printf("zoom: %f\n", e->zoom);
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

int		key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESCAPE)
		ft_fatal_error(e);
	else if (keycode == ARROW_LEFT)
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
	if (keycode == 27)
		e->zoom = e->zoom * 1.5;
	if (keycode == 24)
		e->zoom = e->zoom * 0.75;
	if (keycode == KEY_R)
		frct_init(e, -1);
	if (keycode == KEY_J)
		frct_init(e, JULIA);
	if (keycode == KEY_M)
		frct_init(e, MANDELBROT);
	if (keycode == KEY_K)
		frct_init(e, JUL_3);
	printf("key: %d\n", keycode);
	printf("iter_max: %d\n", e->iter_max);
	frct_draw(e);
	return (0);
}

int		expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win->ptr, e->img->ptr, 0, 0);
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
