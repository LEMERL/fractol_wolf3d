/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 22:45:29 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/12 21:23:14 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_tabnew(size_t size)
{
	char	**tab;

	tab = (char**)ft_strnew((size + 1) * sizeof(char*) - 1);
	return ((void*)tab);
}

char	**ft_tabdup(char **tab)
{
	int			i;
	char		**ret;

	if (tab == NULL)
		return (NULL);
	i = 0;
	while (tab[i] != NULL)
		i++;
	if ((ret = (char**)ft_tabnew(i)) == NULL)
		return (NULL);
	i = 0;
	while (tab[i] != NULL)
	{
		ret[i] = ft_strdup(tab[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

char	**ft_tabchrstr(char **tab, char *str, int len)
{
	int		i;

	i = 0;
	while (tab != NULL && tab[i] != NULL)
	{
		if (ft_strncmp(tab[i], str, len) == 0)
			return (tab + i);
		i++;
	}
	return (NULL);
}

char	**ft_tabret(char **tab, char *ret)
{
	char		**new_tab;
	int			i;
	int			j;

	j = 0;
	i = 0;
	i = ft_tablen(tab);
	new_tab = (char**)ft_tabnew(i - 1);
	i = 0;
	while (tab[i] != NULL)
	{
		if (ft_strcmp(tab[i], ret) != 0)
			new_tab[j++] = ft_strdup(tab[i]);
		i++;
	}
	new_tab[j] = NULL;
	return (new_tab);
}

char	**ft_tabadd(char **tab, char *add)
{
	char		**new_tab;
	int			i;

	i = 0;
	while (tab && tab[i] != NULL)
		i++;
	new_tab = (char**)ft_tabnew(i + 1);
	i = 0;
	while (tab && tab[i] != NULL)
	{
		new_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	new_tab[i] = ft_strdup(add);
	new_tab[i + 1] = NULL;
	return (new_tab);
}
