#include "fract.h"
#include "ft_event.h"

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
	else if (button == 5)
		e->zoom = e->zoom * 1.5;
	if (button == 2 && e->focus == 1)
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
	printf("zoom: %f\n", e->zoom);
	printf("e->win->height / (e->max.real - e->min.real) == %f\n", e->win->height / (e->max.real - e->min.real));
	frct_draw(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	printf("key: %d\n", keycode);
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
		frct_init(e, MANDELBROT);
	printf("iter_max: %d\n", e->iter_max);
	printf("zoom: %g\n", e->zoom);
	printf("1000 / zoom: %g\n\n", 1000.0 / e->zoom);
	frct_draw(e);
	(void)keycode;
	(void)e;
	return (0);
}
//if (e->zoom / (1000 * 1000) < 3284788053552)
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

