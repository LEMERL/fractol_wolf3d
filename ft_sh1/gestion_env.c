/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 16:29:03 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/04 18:36:01 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	sh_setenv(char **argv)
{
	char	**env;
	int		argc;
	char	*str;
	char	**tmp;

	argc = ft_tablen(argv);
	env = get_env(NULL, 0);
	if (argc != 3)
	{
		ft_putendl("setenv: invalid number of argument");
		return ;
	}
	str = ft_strnew(ft_strlen(argv[1]) + ft_strlen(argv[2]) + 1);
	str = ft_strcat(ft_strcat(ft_strcpy(str, argv[1]), "="), argv[2]);
	if ((tmp = get_addr_str_env(argv[1])) != NULL)
	{
		free(*tmp);
		*tmp = str;
		return ;
	}
	env = ft_tabadd(env, str);
	get_env(env, 'r');
	free_tab(env);
	free(str);
}

void	sh_unsetenv(char **argv)
{
	char	**tmp;
	char	**env;
	int		i;

	i = 1;
	env = get_env(NULL, 0);
	while (argv[i] != NULL)
	{
		if ((tmp = get_addr_str_env(argv[i])) != NULL)
		{
			env = ft_tabret(env, *tmp);
			tmp = env;
			env = get_env(env, 'r');
			free_tab(tmp);
		}
		i++;
	}
	if (i == 1)
		ft_putendl("unsetenv: invalid number of argument");
}
