/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:45:59 by mgrimald          #+#    #+#             */
/*   Updated: 2015/01/22 20:28:14 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*dest;
	const char	*sourc;

	if (dst == NULL || src == NULL)
		return (ft_error("ft_memccpy", 's'));
	sourc = src;
	dest = dst;
	i = 0;
	while (i < n)
	{
		dest[i] = sourc[i];
		if (sourc[i] == c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
