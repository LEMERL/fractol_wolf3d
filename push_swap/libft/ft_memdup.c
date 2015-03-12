/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 17:19:06 by mgrimald          #+#    #+#             */
/*   Updated: 2015/01/22 21:03:17 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *s, int len)
{
	char	*dup;

	if ((dup = (char*)malloc(len + 1)) == NULL)
		return (ft_error("ft_memdup", 'm'));
	ft_memcpy(dup, s, 0);
	return (dup);
}
