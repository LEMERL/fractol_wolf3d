/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 16:29:03 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/13 22:46:47 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void		print_env(char **env)
{
	int		i;

	i = -1;
	while (env && env[++i] != NULL)
		ft_putendl(env[i]);
}

static int	setenv_verif(char **argv)
{
	int		argc;

	argc = ft_tablen(argv);
	if (argc != 3)
	{
		ft_putendl("setenv: invalid number of argument");
		ft_putendl("setenv: correct usage \"setenv HEAD_1 body\"");
		return (1);
	}
	if (ft_strchr(argv[1], '=') != NULL)
	{
		ft_putendl("setenv: syntax error (forbidden use of '=' in head");
		ft_putendl("setenv: correct usage \"setenv HEAD_1 body\"");
		return (1);
	}
	return (0);
}

void		sh_setenv(char **argv)
{
	char	**env;
	char	*str;
	char	**tmp;

	env = get_env(NULL, 0);
	if (setenv_verif(argv) == 1)
		return ;
	str = ft_strnew(ft_strlen(argv[1]) + ft_strlen(argv[2]) + 1);
	str = ft_strcat(ft_strcat(ft_strcpy(str, argv[1]), "="), argv[2]);
	if ((tmp = get_addr_str_env(argv[1])) != NULL)
	{
		ft_memdel((void**)tmp);
		*tmp = ft_strdup(str);
		ft_memdel((void**)&str);
		return ;
	}
	get_env((env = ft_tabadd(env, str)), 'r');
	free_tab(env);
	ft_strdel(&str);
}

void		sh_unsetenv(char **argv)
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
	{
		ft_putendl("unsetenv: invalid number of argument");
		ft_putendl("unsetenv: correct usage \"unsetenv HEAD_1 Head_2 ...\"");
	}
}
