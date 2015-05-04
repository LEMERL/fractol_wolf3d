/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 22:45:29 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/04 18:29:08 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **tab)
{
	int			i;
	char		**ret;

	if (tab == NULL)
		return (NULL);
	i = 0;
	while (tab[i] != NULL)
		i++;
	if ((ret = (char**)malloc(sizeof(char*) * (i + 1))) == NULL)
		return (NULL);//ft_error();
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

int		ft_tablen(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

char	**ft_tabret(char **tab, char *ret)
{
	char		**new_tab;
	int			i;
	int			j;

	j = 0;
	i = 0;
	i = ft_tablen(tab);
	new_tab = (char**)malloc(sizeof(char*) * (i));
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
	while (tab[i] != NULL)
		i++;
	new_tab = (char**)malloc((sizeof(char*) * (i + 2)));
	i = 0;
	while (tab[i] != NULL)
	{
		new_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	new_tab[i] = ft_strdup(add);
	new_tab[i + 1] = NULL;
	return (new_tab);
}
