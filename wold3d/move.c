#include "wolf.h"

int		can(t_struct ***s, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (s[i / 20])
	{
		j = 0;
		while (s[i / 20][j / 20])
		{
			j++;
			if (i == x && j == y && s[i / 20][j / 20]->z == 0)
			{
				ft_putendl("a");
				if (s[i / 20][(j + 20) / 20]->z == 0)
				return (1);
			}
		}
		i++;
	}
	return (-1);
}

int		move(t_env *env, int x, int y)
{
	int		ret;

	ret = can (env->tab, env->player.x + x, env->player.y + y);
	if (ret == 1)
	{
			ft_putendl("b");
		env->player.x += x;
		env->player.y += y;
		return (1);
	}
	return (-1);
}
