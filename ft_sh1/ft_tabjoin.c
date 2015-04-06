/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 22:45:29 by mgrimald          #+#    #+#             */
/*   Updated: 2015/04/06 21:29:25 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	maj_env(t_env *env, char ***tab_env)
{
	int		j;

	j = 0;
	while (tab_env[j] != NULL)
	{
		while (strcmp("PATH", tab_env[j][0]) == 0 && tab_env[j][v + 1] != NULL)
		j++;
	}
	while 
}

void	print_env(char **env)
{
	int		i;

	i = -1;
	while (env[++i] != NULL)
		ft_putendl(env[i]);
	ft_putstr("\n\n");
}

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_tabadd(char **tab, char *add)
{
	char		**new_tab;
	int			i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	new_tab = (char**)malloc((sizeof(char*) * (i + 2)));
	i = 0;
	while (tab[i] != NULL)
	{
		new_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	new_tab[i] = add;
	new_tab[i + 1] = NULL;
	free(tab);
	return (new_tab);
}

char	**ft_remove_1(char **tab, char *str)
{
	char		**new_tab;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
		i++;
	new_tab = (char**)malloc((sizeof(char*) * (i + 1)));
	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		if (ft_strcmp(tab[i], str) == 0)
		{
		//	free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		else
		{
			new_tab[j] = tab[i];
			i++;
			j++;
		}
	}
	while (tab[i] != NULL)
		new_tab[j++] = tab[i++];
	new_tab[j] = NULL;
	free(tab);
	return (new_tab);
}
