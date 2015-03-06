#include "wolf.h"

int		can_move(t_struct ***s, int x, int y, int n)
{
	int		i;
	int		j;

	i = -1;
	while (s[++i / 20] && (j = -1) + 2)
		while (s[i / 20][++j / 20])
		{
			if (i == x && j == y && s[i / 20][j / 20]->z == 0
					&& s[i / 20][(j / 20) + 1]->z == 0)
			{
				if (n == 0)
					return (1);
				else
					return (can_move(s, x + 20, y, 0));
			}
			if (i == x && j == y && (s[i / 20][j / 20]->z != 0
					|| s[i / 20][(j / 20) + 1]->z != 0))
				return (-1);
		}
	return (-1);
}

int		move(t_env *env, int x, int y)
{
	int		ret;

	ret = can_move(env->tab, env->player.x + x, env->player.y + y, 1);
	if (ret >= 1)
	{
		env->player.x += x;
		env->player.y += y;
		return (1);
	}
	return (-1);
}
