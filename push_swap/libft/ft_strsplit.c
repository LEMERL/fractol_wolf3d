/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 09:45:21 by mgrimald          #+#    #+#             */
/*   Updated: 2015/01/22 21:35:18 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_str(char const *s, char c)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			k++;
		i++;
	}
	return (k);
}

static char		*write_str(char const *s, char c, int *lgt, char *str)
{
	int a;
	int b;

	b = 0;
	while (s[(*lgt)] == c && s[(*lgt)])
		*lgt = *lgt + 1;
	while (s[b + *lgt] != c && s[*lgt + b])
		b++;
	str = ft_strnew(b + 1);
	if (!str)
		return (ft_error("ft_strsplit/write_str", 'm'));
	a = 0;
	while (s[(*lgt)] != c && s[(*lgt)])
	{
		str[a] = s[(*lgt)];
		*lgt = *lgt + 1;
		a++;
	}
	str[a] = 0;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	tab = 0;
	if (!s)
		return (ft_error("ft_strsplit", 's'));
	k = count_str(s, c);
	tab = malloc(sizeof(*tab) * (k + 1));
	if (!tab)
		return (ft_error("ft_strsplit", 'm'));
	while (i < k)
	{
		tab[i] = write_str(s, c, &j, tab[i]);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
