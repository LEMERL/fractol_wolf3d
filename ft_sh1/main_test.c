#include "sh1.h"

char	**sh_unsetenv(char **old_env, char *str);

int		main(int ac, char **av, char **env)
{
	int		i;
	char	**env_tmp;
(void)ac;
	print_env(env);
	i = 0;
	while (env[i] != NULL)
		i++;
	env_tmp = (char**)malloc(sizeof(char*) * i);
	i = -1;
	while (env[++i] != NULL)
		env_tmp[i] = env[i];
	env_tmp[i] = NULL;
	i = 0;
	while (av[i] != NULL)
	{
		env_tmp = ft_tabadd(env_tmp, av[i++]);
		print_env(env_tmp);
	}
	while (--i >= 0)
	{
		env_tmp = sh_unsetenv(env_tmp, av[i]);
		print_env(env_tmp);
	}
	return (0);
}

char	**sh_unsetenv(char **old_env, char *str)
{
	char		**newenv;

	newenv = ft_remove_1(old_env, str);
	return (newenv);
}
