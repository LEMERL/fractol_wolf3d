/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:38:10 by mgrimald          #+#    #+#             */
/*   Updated: 2015/08/07 13:28:22 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	str = NULL;
	str = ft_strnew(len);
	if (str == NULL || start + len > ft_strlen(s))
		return (NULL);
	while (i < len + start)
	{
		if (i >= start)
			str[i - start] = s[i];
		i++;
	}
	return (str);
}
