/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 22:45:29 by mgrimald          #+#    #+#             */
/*   Updated: 2015/04/04 22:53:30 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	**ft_tabadd(char **tab, char *add)
{
	char		**new_tab;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
		i++;
	new_tab = (char**)malloc((sizeof(char*) * i + 1));
	i = 0;
	while (tab[i] != NULL)
	{
		new_tab[i] = tab[i];
		i++;
	}
	new_tab[i] = add;
	new_tab[i + 1] = NULL;
	return (tab);
}
