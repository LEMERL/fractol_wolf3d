/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 21:49:33 by mgrimald          #+#    #+#             */
/*   Updated: 2015/01/22 23:36:09 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_error(char *str, int c)
{
	ft_putstr_fd("/!\\An error occured :\n", 2);
	if (c == 'm')
		ft_putstr_fd("allocation failled\n", 2);
	if (c == 's')
		ft_putstr_fd("NULL ptr unwanted detected\n", 2);
	ft_putstr_fd("This error occured in ", 2);
	if (str)
		ft_putstr_fd(str, 2);
	else
	{
		ft_putstr_fd("\nAN ERROR OCCURED\n", 2);
		ft_putstr_fd("AN ERROR OCCURED\n", 2);
		ft_putstr_fd("AN ERROR OCCURED\nWITHIN THE ERROR SYSTEM\n", 2);
	}
	ft_putstr_fd("\naborbtion of the current process", 2);
	ft_putstr_fd("to avoid any segfault\n", 2);
	return (NULL);
}
