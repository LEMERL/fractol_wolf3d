/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:16:42 by mgrimald          #+#    #+#             */
/*   Updated: 2015/01/22 22:14:49 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*b1;
	unsigned char	*b2;

	if (s1 == NULL || s2 == NULL)
	{
		ft_error("ft_memcmp", 's');
		return (0);
	}
	b1 = (unsigned char*)s1;
	b2 = (unsigned char*)s2;
	while (n)
	{
		if (*b1 != *b2)
			return (*b1 - *b2);
		b1++;
		b2++;
		n--;
	}
	return (0);
}
