/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 12:29:52 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/12 20:56:48 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	char			*ptr;

	if (!s || !f)
		return (NULL);
	i = 0;
	ptr = (char*)s;
	while (ptr[i])
		i++;
	str = ft_strnew(i);
	i = 0;
	while (ptr[i])
	{
		str[i] = (*f)(i, ptr[i]);
		i++;
	}
	return ((char*)str);
}
