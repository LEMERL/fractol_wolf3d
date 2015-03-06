#include "wolf.h"
#include <stdio.h>
#include "keycode.h"

int		expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img->ptr, 0, 0);
	mlx_put_image_to_window(e->mlx, e->win, e->player.img->ptr, e->player.x, e->player.y);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	printf("key: %d\n", keycode);
	if (keycode == KEY_ESCAPE)
		exit(0);
	if (keycode == NUM_PAD_5)
	{
		e->player.x = 20;
		e->player.y = 20;
	}
	if (keycode == KEY_DOWN)
		move(e, 0, 25);
	if (keycode == KEY_UP)
		move(e, 0, -25);
	if (keycode == KEY_LEFT)
		move(e, -25, 0);
	if (keycode == KEY_RIGHT)
		move(e, 25, 0);
	expose_hook(e);
	return (0);
}

void	wolf2d_mlx(t_env *env)
{
	mlx_key_hook(env->win, key_hook, env);
	mlx_expose_hook(env->win, expose_hook, env);
//	mlx_mouse_hook(env->win, mouse_hook, env);
	mlx_loop(env->mlx);
}

//	mlx_hook(env->win->ptr, 6, (1L << 6), motion_hook, env);

