/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 18:49:29 by mgrimald          #+#    #+#             */
/*   Updated: 2015/04/06 19:17:07 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	sh_cd(t_env *env, char **arg)
{
	int		ret;
	char	*dir;
	char	*str;

	dir = NULL;
	if (arg == NULL || arg[0] == NULL)
		ret = chdir(env->home);
	else if (arg[1] != NULL)
		ft_putendl("error: cd: too many arguments");
	else if (ft_strcmp(arg[0], "-") == 0)
		dir = env->oldpwd;
	else if (ft_strncmp(arg[0], "~", 1) == 0)
		dir = ft_strjoin(env->home, arg[0] + 1);
	else
		dir = arg[0];
	if (dir != NULL && access(dir, F_OK|X_OK) == 0 && chdir(dir) == 0)
	{
		free(env->oldpwd);
		env->oldpwd = env->pwd;
		str = ft_strnew(1024);
		env->pwd = getcwd(str, 1024);
	}
}
