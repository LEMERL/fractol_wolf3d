/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 18:18:19 by mgrimald          #+#    #+#             */
/*   Updated: 2015/01/22 22:12:19 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		j;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (ft_error("ft_strstr", 's'));
	str = (char*)s1;
	j = 0;
	if (s2[j] == '\0')
		return (str);
	while (*str != '\0')
	{
		while (str[j] == s2[j])
		{
			j++;
			if (s2[j] == '\0')
				return (str);
		}
		str++;
		j = 0;
	}
	return (NULL);
}
