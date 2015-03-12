/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 20:07:43 by mgrimald          #+#    #+#             */
/*   Updated: 2015/01/22 21:32:07 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*temp;
	int		i;
	int		j;

	if (str == NULL)
		return (ft_error("ft_strrev", 's'));
	i = ft_strlen(str) - 1;
	if ((temp = ft_strnew(i)) == NULL)
		return (ft_error("ft_strrev", 'm'));
	while (i > 0)
	{
		temp[j] = str[i];
		i--;
		j++;
	}
	temp[j] = '\0';
	ft_strcpy(str, temp);
	free(temp);
	return (str);
}
