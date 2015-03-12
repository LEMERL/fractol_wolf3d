/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 18:17:50 by mgrimald          #+#    #+#             */
/*   Updated: 2015/01/22 21:07:42 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*sourc;

	sourc = (void *)src;
	dest = dst;
	if (dst == NULL || src == NULL)
		return (ft_error("ft_memmove", 's'));
	if (dest <= sourc)
		return (ft_memcpy(dst, src, n));
	while (n)
	{
		n--;
		dest[n] = sourc[n];
	}
	return (dst);
}
