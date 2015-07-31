/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fatal_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 14:49:40 by mgrimald          #+#    #+#             */
/*   Updated: 2015/07/31 21:22:55 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_fatal_error(t_env *e)
{
	void	*antileaks;

	antileaks = NULL;
	if (e != NULL)
	{
		if (e->img)
		{
			if (e->img->ptr)
				mlx_destroy_image(e->mlx, e->img->ptr);
			ft_memdel((void**)&(e->img));
		}
		if (e->win)
		{
			if (e->win->ptr)
				mlx_destroy_window(e->mlx, e->win->ptr);
			ft_memdel((void**)&(e->win));
		}
		if (e->mlx)
			antileaks = e->mlx;
		ft_memdel((void**)&e);
	}
	wait(NULL);
	exit(0);
}
