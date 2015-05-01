/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 16:29:03 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/01 18:42:55 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

t_env	sh_setenv_already_in(t_list *list, t_env env);
t_env	sh_setenv_not_in(t_env env);
void	fill_strc_env(char *str, t_env *strc);

void	sh_add_to_env(char **env, t_env *strc, char *add);
void	sh_rem_to_env(char **env, t_env *strc, char *rem);

void	sh_add_to_env(char **env, t_env *strc, char *add)
{
	int			i;

	i = 0;
	strc->env = (char**)malloc(sizeof(char*) * (i + 2));
	i = 0;
	while (env[i] != NULL)
	{
		strc->env[i] = env[i];
		i++;
	}
	strc->env[i] = ft_strdup(add);
	fill_strc_env(strc->env[i], strc);
	strc->env[i + 1] = NULL;
}

void	sh_setenv(t_env *strc, char *add)
{
	char	**tmp;
	int		i;
	int		v;

	i = 0;
	v = 1;
	tmp = strc->env;
	while (tmp && tmp[i] != NULL && v != 0)
	{
		if (ft_strncmp(strc->env[i], add, ft_strlen(add)) != 0)
		{
			v = 0;
			free(strc->env[i]);
			strc->env[i] = ft_strdup(add);
			fill_strc_env(add, strc);
		}
		i++;
	}
	if (v != 0)
	{
		sh_add_to_env(strc->env, strc, add);
		free(tmp);
	}
}

void	sh_unsetenv(t_env *strc, char *del)
{
	void *tmp;

	tmp = strc->env;
	sh_rem_to_env(strc->env, strc, del);
	free(tmp);
	tmp = NULL;
}


void	sh_rem_to_env(char **env, t_env *strc, char *rem)
{
	int			i;
	int			j;
	int			v;

	i = 0;
	v = 1;
	while (env && env[i] != NULL && v != 0)
	{
		if (ft_strncmp(strc->env[i], rem, ft_strlen(rem)) == 0)
			v = 0;
		i++;
	}
	if (v == 1)
		return ;
	strc->env = (char**)malloc(sizeof(char*) * (i));
	j = 0;
	i = 0;
	while (env[i] != NULL)
	{
		strc->env[j] = env[i];
		fill_strc_env(strc->env[j], strc);
		if (ft_strncmp(env[i], rem, ft_strlen(rem)))
			j++;
		else
		{
			free(env[i]);
			env[i] = NULL;
		}
		i++;
	}
	strc->env[j] = NULL;
}

void	get_first_env(char **env, t_env *strc)
{
	int			i;

//	if (env == NULL || *env == NULL)
//		env = prefabriced_env();
	i = 0;
	while (env[i] != NULL)
		i++;
	strc->env = (char**)malloc(sizeof(char*) * (i + 1));
	strc->env[i] = NULL;
	i = -1;
	while (env[++i] != NULL)
	{
		strc->env[i] = ft_strdup(env[i]);
		fill_strc_env(strc->env[i], strc);
	}
}

void	fill_strc_env(char *str, t_env *strc)
{
	if (ft_strncmp(str, "PATH", 4) == 0)
	{
		if (strc->path != NULL)
			free_tab(strc->path);
		strc->path = ft_strsplit(ft_strchr(str, '='), ':');
	}
	else if (ft_strncmp(str, "HOME", 4) == 0)
	{
		if (strc->home != NULL)
			strc->home = NULL;
		strc->home = ft_strchr(str, '=');
	}
	else if (ft_strncmp(str, "PWD", 3) == 0)
	{
		if (strc->pwd != NULL)
			strc->pwd = NULL;
		strc->pwd = ft_strchr(str, '=');
	}
	else if (ft_strncmp(str, "OLDPWD", 6) == 0)
	{
		if (strc->oldpwd != NULL)
			strc->oldpwd = NULL;
		strc->oldpwd = ft_strchr(str, '=');
	}
}
