/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 18:17:36 by mgrimald          #+#    #+#             */
/*   Updated: 2015/01/22 20:31:14 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dest;
	char		*sourc;

	sourc = (void *)src;
	dest = dst;
	if (dst == NULL || src == NULL)
		return (ft_error("ft_memcpy", 's'));
	i = 0;
	while (i < n && (dest + i))
	{
		dest[i] = sourc[i];
		i++;
	}
	return (dest);
}
