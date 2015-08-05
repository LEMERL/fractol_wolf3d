/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:34:50 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/14 14:34:23 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	nbr;
	int sign;
	int	i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\n' || str[i] == '\v' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		if (nbr < -214748364 || (nbr == -214748364 && str[i] >= '9'))
			return (-1);
		else if (nbr > 214748364 || (nbr == 214748364 && str[i] >= '8'))
			return (-1);
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}
