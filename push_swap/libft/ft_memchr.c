/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:58:50 by mgrimald          #+#    #+#             */
/*   Updated: 2015/01/22 22:12:49 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;

	str = s;
	i = 0;
	if (s == NULL)
		return (ft_error("ft_memchr", 's'));
	while (str + i && (n == 0 || i < n))
	{
		if (str[i] == (unsigned char)c)
			return ((void*)str + i);
		i++;
	}
	return (NULL);
}
