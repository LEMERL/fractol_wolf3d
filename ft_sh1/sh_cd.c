/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 18:49:29 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/04 19:23:08 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	sh_cd(char **arg)
{
	char	*dir;
	char	**pwd;
	char	**oldpwd;

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
		dir = arg[1];
	if (dir != NULL && access(dir, F_OK|X_OK) == 0 && chdir(dir) == 0)
	{
		pwd = get_addr_str_env("PWD");
		oldpwd = get_addr_str_env("OLDPWD");
		free(*oldpwd);
		*oldpwd = *pwd;
		*pwd = getcwd(NULL, 0);
	}
	else
		ft_putendl("cd: usage: cd [~|~/dir|-|dir]");
	if (dir != NULL)
		free(dir);
}
