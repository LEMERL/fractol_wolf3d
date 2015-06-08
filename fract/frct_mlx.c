#include "fract.h"
/*
int		frct_zoom(t_env *e, t_env *tmp, double center)
{
	return (0);
}
*/
int		mouse_hook(int button, int x, int y, t_env *e)
{

	if (button == 4)
		e->zoom = e->zoom * 0.75;
	if (button == 5)
		e->zoom = e->zoom * 1.5;
	if (button == 1)
		e->focus = e->focus ? 0 : 1;
//	if (e->min.real >= e->max.real || e->min.real >= e->max.real)
	printf("button: %d\n", button);
	printf("x: %d\ty%d\n", x, y);
	printf("center.real: %f\tcenter.cmplx: %f\n", e->centre.real, e->centre.cplx);
	printf("min.real: %f\tmax.real: %f\n", e->min.real, e->max.real);
	printf("min.cplx: %f\tmax.cplx: %f\n", e->min.real, e->max.real);
	printf("zoom: %f\n", e->zoom);
	printf("e->win->height / (e->max.real - e->min.real) == %f\n", e->win->height / (e->max.real - e->min.real));
	frct_draw(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	printf("key: %d\n", keycode);
	if (keycode == 65307)
		ft_fatal_error(e);
//	if (keycode == 65451 || keycode == 61)
//	if (keycode == 65453 || keycode == 45)
/*	if (keycode == 65461)
	{
		e->min.real = -2.0;
		e->max.real = 2.0;
		e->min.cplx = -2.0;
		e->max.cplx = 2.0;
	}*/
	if (keycode == 61)
		e->iter_max += 10;
	if (keycode == 45)
		e->iter_max -= 10;
	frct_draw(e);
	(void)keycode;
	(void)e;
	return (0);
}

int		expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win->ptr, e->img->ptr, 0, 0);
	return (0);
}

void	frct_mlx(t_env *env)
{
	mlx_key_hook(env->win->ptr, key_hook, env);
	mlx_expose_hook(env->win->ptr, expose_hook, env);
	mlx_mouse_hook(env->win->ptr, mouse_hook, env);
	mlx_loop(env->mlx);
}

//	mlx_hook(env->win->ptr, 6, (1L << 6), motion_hook, env);

