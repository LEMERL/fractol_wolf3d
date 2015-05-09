/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 18:49:29 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/09 17:54:51 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	change_pwd_old(char *futur_old)
{
	char	**pwd;
	char	**oldpwd;
	char	*str;
	char	*tmp;

	pwd = get_addr_str_env("PWD");
	str = getcwd(NULL, 0);
	tmp = ft_strjoin("OLDPWD=", futur_old);
	if ((oldpwd = get_addr_str_env("OLDPWD"))== NULL)
		ft_tabadd(get_env(NULL, 0), tmp);
	else
	{
		free(*oldpwd);
		*oldpwd = ft_strjoin("OLDPWD=", futur_old);
	}
	free(tmp);
	tmp = ft_strjoin("OLDPWD=", str);
	if ((pwd = get_addr_str_env("PWD")) == NULL)
		ft_tabadd(get_env(NULL, 0), tmp);
	else
	{
		free(*pwd);
		*pwd = ft_strjoin("PWD=", str);
	}
	free(str);
	free(tmp);
	ft_putstr("\ncd: success\nnew PWD:\t");
	ft_putendl(get_str_env("PWD"));
	ft_putstr("new OLDPWD :\t");
	ft_putendl(get_str_env("OLDPWD"));
}

void	try_access(char *dir)
{
	char	*futur_old;

	if (access(dir, F_OK) == 0)
	{
		futur_old = getcwd(NULL, 0);
		if (access(dir, X_OK) == 0 && chdir(dir) == 0)
			change_pwd_old(futur_old);
		else
		{
			ft_putstr("cd: permission denied: ");
			ft_putendl(dir);
		}
		free(futur_old);
	}
	else
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(dir);
	}
}

void	sh_cd(char **arg)
{
	char	*dir;

	dir = NULL;
	if (arg == NULL || arg[1] == NULL)
		dir = ft_strdup(get_str_env("HOME"));
	else if (arg[1] != NULL && arg[2] != NULL)
		ft_putendl("error: cd: too many arguments");
	else if (ft_strcmp(arg[1], "-") == 0)
		dir = ft_strdup(get_str_env("OLDPWD"));
	else if (ft_strncmp(arg[1], "~", 1) == 0)
		dir = ft_strjoin(get_str_env("HOME"), arg[1] + 1);
	else
		dir = ft_strdup(arg[1]);
	if (dir != NULL)
	{
		try_access(dir);
		free(dir);
	}
	else
		ft_putendl("cd: usage \"cd [~|-| |path-to-dir]\"");
}
