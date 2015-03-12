/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:32:20 by mgrimald          #+#    #+#             */
/*   Updated: 2015/01/22 20:57:42 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return (ft_error("ft_strdup", 's'));
	while (s1[i] != '\0')
		i++;
	if ((s2 = ft_strnew(i)) == NULL)
		return (ft_error("ft_strdup", 'm'));
	while (j <= i)
	{
		s2[j] = s1[j];
		j++;
	}
	return (s2);
}
