/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:45:32 by mgrimald          #+#    #+#             */
/*   Updated: 2015/01/22 20:50:24 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*vi;

	if (s == NULL)
		return (ft_error("ft_strchr", 's'));
	vi = (char*)s;
	i = 0;
	while (i == 0 || s[i - 1] != '\0')
	{
		if (s[i] == c)
			return (vi + i);
		i++;
	}
	return (NULL);
}
