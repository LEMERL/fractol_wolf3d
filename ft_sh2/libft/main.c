/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 14:25:55 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/14 14:27:58 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		main(int argc, char **argv)
{
	argv++;
	while (argv && *argv != NULL)
	{
		ft_putendl(ft_itoa(ft_atoi(*argv)));
		argv++;
	}
	return (0);
}

