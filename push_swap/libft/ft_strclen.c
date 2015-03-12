/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 17:09:04 by mgrimald          #+#    #+#             */
/*   Updated: 2015/01/22 20:48:01 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strclen(const char *s, int c)
{
	size_t	size;

	size = 0;
	if (s == NULL)
	{
		ft_error("ft_strclen", 's');
		return (-1);
	}
	while (s[size] != '\0' && s[size] != (unsigned char)c)
		size++;
	if (s[size] == (unsigned char)c)
		return (size);
	return (-1);
}
