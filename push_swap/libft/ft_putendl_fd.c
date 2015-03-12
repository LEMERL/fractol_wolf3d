/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:25:52 by mgrimald          #+#    #+#             */
/*   Updated: 2015/01/22 20:37:44 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	if (s == NULL)
		ft_error("ft_putendl_fd", 's');
	else
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
	}
}
