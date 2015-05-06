/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 18:49:29 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/06 20:22:50 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	change_pwd_old(void)
{
	char	**pwd;
	char	**oldpwd;
	char	*str;

	pwd = get_addr_str_env("PWD");
	oldpwd = get_addr_str_env("OLDPWD");
	free(*oldpwd);
	*oldpwd = ft_strjoin("OLDPWD=", ft_strchr(*pwd, '=') + 1);
	free(*pwd);
	str = getcwd(NULL, 0);
	*pwd = ft_strjoin("PWD=", str);
	ft_putstr("\ncd: success\nnew PWD:\t");
	ft_putendl(get_str_env("PWD"));
	ft_putstr("new OLDPWD :\t");
	ft_putendl(get_str_env("OLDPWD"));
	free(str);
}

void	try_access(char *dir)
{
	if (access(dir, F_OK) == 0)
	{
		if (access(dir, X_OK) == 0 && chdir(dir) == 0)
			change_pwd_old();
		else
		{
			ft_putstr("cd: permission denied: ");
			ft_putendl(dir);
		}
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
