/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 13:25:27 by mgrimald          #+#    #+#             */
/*   Updated: 2015/04/15 17:45:30 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char		**prefabriced_env(void);
t_sub_env	sh_fill_strc(char *str);

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
