/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 16:29:03 by mgrimald          #+#    #+#             */
/*   Updated: 2015/04/16 16:08:17 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

t_sub_env	sh_fill_strc(char *str)
{
	t_sub_env	strc;
	int			i;

	strc.full = ft_strdup(str);
	strc.head = ft_strdup(str);
	while (strc.head[i] != '\0' && strc.head[i] != '=')
		i++;
	strc.head[i] = '\0';
	strc.body = strc.head + i;
	return (strc);
}

char	**maj_env(t_list *lst)
{
	char	**env;
	t_list	*ptr;
	int		i;
	int		j;

	ptr = lst;
	i = 0;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		i++;
	}
	env = (char**)malloc(sizeof(char*) * (i + 1));
	env[i] = NULL;
	j = 0;
	ptr = lst;
	while (ptr != NULL)
	{
		env[j] = ((t_sub_env *)lst->content)->full;
		j++;
		ptr = ptr->next;
	}
	return (env);
}

char	**prefabriced_env(void)
{
	char	**tab;
	tab = (char**)malloc(sizeof(char*) * 6);
	tab[5] = NULL;
	tab[0] = ft_strdup("PATH=");
	tab[1] = ft_strdup("PWD=/");
	tab[2] = ft_strdup("OLDPWD=/");
	tab[3] = ft_strdup("SHLVL=1");
	tab[4] = ft_strdup("SHELL=minishell");
	return (tab);
}

t_env	sh_setenv(t_env env, char *add)
{
		if (ft_strncmp(add, "PATH", 4) == 0)
			env.path = ft_strsplit(((t_sub_env*)envilist->content)->body, ':');
		if (ft_strncmp(add, "HOME", 4) == 0)
		{
			env.home = ((t_sub_env*)env.list->content)->body;
			}
			if (ft_strncmp(add, "PWD", 3) == 0)
			env.pwd = ((t_sub_env*)env.list->content)->body;
		if (ft_strncmp(add, "OLDPWD", 6) == 0)
			env.oldpwd = ((t_sub_env*)env.list->content)->body;
	ft_tabdel(env.env);
	env.env = maj_env(env.list);
	return (env);
}

void	gt_env(char **env, t_env *strc)
{
	t_list		*lst;
	t_sub_env	st;
	int			i;

	if (env == NULL || *env == NULL)
		env = prefabriced_env();
	lst = ft_lstnew(NULL, 0);
	i = -1;
	while (env[++i] != NULL)
	{
		st = sh_fill_strc(env[i]);
		ft_lstadd(&lst, ft_lstnew(&st, sizeof(t_sub_env)));
		if (ft_strcmp(((t_sub_env*)lst->content)->head, "PATH") == 0)
			strc->path = ft_strsplit(((t_sub_env*)lst->content)->body, ':');
		if (ft_strcmp(((t_sub_env*)lst->content)->head, "HOME") == 0)
			strc->home = ((t_sub_env*)lst->content)->body;
		if (ft_strcmp(((t_sub_env*)lst->content)->head, "PWD") == 0)
			strc->pwd = ((t_sub_env*)lst->content)->body;
		if (ft_strcmp(((t_sub_env*)lst->content)->head, "OLDPWD") == 0)
			strc->oldpwd = ((t_sub_env*)lst->content)->body;
	}
	strc->env = env;
	strc->list = lst;
}
