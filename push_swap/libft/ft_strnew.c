/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:38:37 by mgrimald          #+#    #+#             */
/*   Updated: 2015/01/22 21:28:24 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*str;
	size_t		i;
	size_t		j;

	i = 0;
	j = size;
	if ((str = (char*)malloc(j + 1)) == NULL)
		return (ft_error("ft_strnew", 'm'));
	while (i <= j)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
