/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 14:36:39 by mgrimald          #+#    #+#             */
/*   Updated: 2015/01/22 21:40:26 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strnewcpy(char *str)
{
	int		i;
	char	*nws;

	nws = NULL;
	i = 0;
	while (str[i] != '\0')
		i++;
	if ((nws = ft_strnew(i)) == NULL)
		return (ft_error("ft_strtrim/ft_strnewcpy", 'm'));
	i = 0;
	while (str[i] != '\0' && (nws + i) != NULL)
	{
		nws[i] = str[i];
		i++;
	}
	nws[i] = '\0';
	return (nws);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	char	*str;
	char	*ptr;

	if (s == NULL)
		return (ft_error("ft_strtrim", 's'));
	i = ft_strlen(s) - 1;
	str = (char*)s;
	if (str[0] == '\0' || ((str[0] != '\n' && str[0] != '\t' && str[0] != ' ')
		&& (str[i] != '\n' && str[i] != '\t' && str[i] != ' ')))
		return (ft_strnewcpy(str));
	while ((*str == ' ' || *str == '\n' || *str == '\t') && *str)
		str++;
	i = ft_strlen(str) - 1;
	while ((str[i] == '\n' || str[i] == '\t' || str[i] == ' ') && i > 0)
		i--;
	i++;
	if ((ptr = ft_strdup(str)) == NULL)
		return (ft_error("ft_strtrim", 'm'));
	ptr[i] = '\0';
	return (ptr);
}
