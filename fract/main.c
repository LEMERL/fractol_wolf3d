#include "fract.h"

int		main(int argc, char **argv)
{
	t_env	*env;

	if ((env = (t_env*)malloc(sizeof(t_env))) == NULL)
		ft_fatal_error(env);
	frct_argument(env, argc, argv);
	frct_init(env);

	frct_draw(env);
	frct_mlx(env);
	return (0);
}
