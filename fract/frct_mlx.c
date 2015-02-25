#include "fract.h"

int		mouse_hook(int button, int x, int y, t_env *e)
{
	double	delta;
	double	center;
	t_env	tmp;

	tmp.y_max = e->y_max;
	tmp.y_min = e->y_min;
	tmp.x_max = e->x_max;
	tmp.x_min = e->x_min;
	if (button == 4)
	{
		delta = e->x_max - e->x_min;
		delta = (delta * 4) / 3;
		if (delta <= 0.0)
			delta = 0.01;
		center = (e->x_max + e->x_min) / 2;
		e->x_min = center + (delta / 2);
		e->x_max = center - (delta / 2);
		delta = e->y_max - e->y_min;
		delta = (delta * 4) / 3;
		if (delta <= 0.0)
			delta = 0.01;
		center = (e->x_max + e->x_min) / 2;
		delta = (delta * 4) / 3;
		e->y_min = center + (delta / 2);
		e->y_max = center - (delta / 2);
	}
	if (button == 5)
	{
		delta = e->x_max - e->x_min;
		if (delta <= 0.0)
			delta = 0.01;
		delta = (delta * 3) / 4;
		e->x_min = e->x_min - (x - (delta / 2)) / e->zoom;
		e->x_max = e->x_max + (x + (delta / 2)) / e->zoom;
		delta = e->y_max - e->y_min;
		if (delta <= 0.0)
			delta = 0.01;
		delta = (delta * 3) / 4;
		e->y_min = e->y_min - (y - (delta / 2)) / e->zoom;
		e->y_max = e->y_max + (y - (delta / 2)) / e->zoom;
	}
	if (button == 1)
		e->focus = e->focus ? 0 : 1;
	if (e->x_min >= e->x_max || e->x_min >= e->x_max)
	{
		e->y_max = tmp.y_max;
		e->x_max = tmp.x_max;
		e->y_min = tmp.y_min;
		e->x_min = tmp.x_min;
	}
	printf("button: %d\n", button);
	printf("delta: %f\n", delta);
	printf("x: %d\ty%d\n", x, y);
	printf("x_min: %f\tx_max$%f\n", e->x_min, e->x_max);
	printf("y_min: %f\ty_max$%f\n", e->x_min, e->x_max);
	printf("zoom: %f\n", e->win->height / (e->x_max - e->x_min));
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
	if (keycode == 65461)
	{
		e->x_min = -2.0;
		e->x_max = 2.0;
		e->y_min = -2.0;
		e->y_max = 2.0;
	}
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

