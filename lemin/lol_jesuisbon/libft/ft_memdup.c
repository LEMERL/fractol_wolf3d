/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 17:19:06 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/12 21:13:14 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *s, int len)
{
	char	*dup;

	if ((dup = ft_strnew(len)) == NULL)
		return (NULL);
	ft_memcpy(dup, s, len);
	return (dup);
}
