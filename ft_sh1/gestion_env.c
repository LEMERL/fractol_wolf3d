/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 16:29:03 by mgrimald          #+#    #+#             */
/*   Updated: 2015/04/26 22:41:55 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

t_env	sh_setenv_already_in(t_list *list, t_env env);
t_env	sh_setenv_not_in(t_env env);
void	fill_env(char *str, t_env *strc);


/*
t_env	sh_setenv(t_env env, char *add)
{
}

t_env	sh_unsetenv(t_env env, char *del)
{
}
*/

void	gt_env(char **env, t_env *strc)
{
	int			i;

//	if (env == NULL || *env == NULL)
//		env = prefabriced_env();
	i = -1;
	while (env[++i] != NULL)
	{
		strc->env[i] = ft_strdup(env[i]);
		fill_env(strc->env[i], strc);
	}
	strc->env = env;
}

void	fill_env(char *str, t_env *strc)
{
	if (ft_strcmp(str, "PATH") == 0)
		strc->path = ft_strsplit(str, ':');
	else if (ft_strcmp(str, "HOME") == 0)
		strc->home = ft_strchr(str, '=');
	else if (ft_strcmp(str, "PWD") == 0)
		strc->pwd = ft_strchr(str, '=');
	else if (ft_strcmp(str, "OLDPWD") == 0)
		strc->oldpwd = ft_strchr(str, '=');
}
