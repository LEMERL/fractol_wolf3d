#include <stdio.h>
#include <stdlib.h>
#include "sh1.h"

int		main(int argc, char *argv[], char **env)
{
	int		j;
	char	**env_tab;
	char	**env_path;
	j = 0;
	while (argv[j] != NULL)
	{
		printf("argv[%d]: %s\n", j, argv[j]);
		j++;
	}
	printf("\n");
	j = 0;
	while (env[j] != NULL)
	{
		printf("env[%d]: %s\n", j, env[j]);
		env_tab = ft_strsplit(env[j], '=');
		if (ft_strcmp(env_tab[0], "PATH") == 0)
			env_path = ft_strsplit(env_tab[1], ':');
		j++;
	}
	printf("\n");
	j = 0;
	while (env_path[j] != NULL)
	{
		printf("env_path[%d]: %s\n", j, env_path[j]);
		j++;
	}
	printf("\n");
	exit(EXIT_SUCCESS);
}
