/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 18:49:29 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/13 21:11:34 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static void	change_pwd_old(char *futur_old)
{
	char	*str;
	char	**tab;

	tab = (char**)ft_tabnew(4);
	tab[0] = ft_strdup("setenv");
	tab[1] = ft_strdup("OLDPWD");
	tab[2] = ft_strdup(futur_old);
	tab[3] = NULL;
	sh_setenv(tab);
	free_tab(tab);
	str = getcwd(NULL, 0);
	tab = (char**)ft_tabnew(4);
	tab[0] = ft_strdup("setenv");
	tab[1] = ft_strdup("PWD");
	tab[2] = ft_strdup(str);
	tab[3] = NULL;
	sh_setenv(tab);
	free_tab(tab);
	ft_strdel(&str);
	ft_putendl(get_str_env("PWD"));
}

static void	try_cd(char *dir)
{
	char	*futur_old;
	int		type;

	ft_putstr("cd: ");
	if ((type = check_file(dir)) == 2)
	{
		futur_old = getcwd(NULL, 0);
		if (chdir(dir) == 0)
			change_pwd_old(futur_old);
		free(futur_old);
	}
	else
	{
		ft_putstr("not a directory: ");
		ft_putendl(dir);
	}
}

void		sh_cd(char **arg)
{
	char	*dir;

	dir = NULL;
	if (arg == NULL || arg[1] == NULL)
		dir = get_str_env("HOME");
	else if (arg[1] != NULL && arg[2] != NULL)
		ft_putendl("error: cd: too many arguments");
	else if (ft_strcmp(arg[1], "-") == 0 &&
			((dir = get_str_env("OLDPWD")) == NULL || *dir == '\0'))
	{
		ft_putstr("I've got a very bad sense of direction.\nI think I'm ");
		ft_putendl("lost, I can't find my way to my previous localisation");
		return ;
	}
	else if (ft_strcmp(arg[1], "-") != 0)
		dir = arg[1];
	if (dir != NULL && *dir != '\0')
	{
		dir = ft_strdup(dir);
		try_cd(dir);
		ft_strdel(&dir);
	}
	else
		ft_putendl("cd: usage \"cd [~|-| |path-to-dir]\"");
}
