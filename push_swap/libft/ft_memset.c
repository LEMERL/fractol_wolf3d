/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:01:46 by mgrimald          #+#    #+#             */
/*   Updated: 2015/01/22 21:07:53 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;
	size_t	i;

	str = b;
	i = 0;
	if (b == NULL)
	{
		ft_error("ft_memset", 's');
		return (0);
	}
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}
