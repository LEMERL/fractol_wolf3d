/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 13:25:27 by mgrimald          #+#    #+#             */
/*   Updated: 2015/04/07 18:09:12 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	**prefabriced_env(void);
void	*sh_fill_strc(char *str);

char	**tab_dup(char **tab)
{
	char		**ret;
	int			i;

	i = 0;
	while (tab && tab[i] != NULL)
		i++;
	ret = malloc(sizeof(char*) * (i + 1));
	ret[i] = NULL;
	i = 0;
	while (tab && tab[i] != NULL)
	{
		ret[i] = ft_strdup(tab[i]);
		i++;
	}
	return (ret);
}

void	gt_env(char **env, t_env *strc)
{
	t_list		*lst;
	t_sub_env	*st;
	int			i;

//	if (env == NULL || *env == NULL)
//		env = prefabriced_env();
//	else
		env = tab_dup(env);
	lst = ft_lstnew(NULL, 0);
	i = -1;
	while (env[++i] != NULL)
	{
		st = sh_fill_strc(env[i]);
		ft_lstadd(&lst, ft_lstnew(st, sizeof(*st)));
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

void	sh_print_env(t_env *env);

void	delete_strc(void *tmp, size_t size)
{
	t_sub_env *strc;

	strc = (t_sub_env*)tmp;
	free(strc->full);
	free(strc->head);
	free(strc->body);
	free(strc);
}

void	*sh_fill_strc(char *str)
{
	t_sub_env	*strc;
	int			i;

	strc = malloc(sizeof(t_sub_env));
	strc->full = str;
	while (str[i] != '\0' && str[i] != '=')
		i++;
	str[i] = '\0';
	strc->head = ft_strdup(str);
	strc->body = ft_strdup(str + i);
	return (strc);
}

void	sh_unset_env(char *str, t_env *env)
{
	t_list	*tmp;

	tmp = env->list;
	while (tmp != NULL)
	{
		if (ft_strcmp(((t_sub_env*)tmp->content)->head, str) == 0)
			ft_lstdelone(&tmp, delete_strc);
		tmp = tmp->next;
	}
	env->env = ft_remove_1(env->env, str);
}

char	**ft_remove_1(char **tab, char *str)
{
	char		**new_tab;
	int			i;
	int			j;

	i = 0;
	while (tab[i] != NULL)
		i++;
	new_tab = (char**)malloc((sizeof(char*) * (i + 1)));
	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		if (ft_strcmp(tab[i], str) == 0)
			free(tab[i]);
		else
			new_tab[j++] = tab[i];
		i++;
	}
	new_tab[j] = NULL;
	free(tab);
	return (new_tab);
}
