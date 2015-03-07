/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fatal_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 14:49:40 by mgrimald          #+#    #+#             */
/*   Updated: 2015/03/07 19:13:22 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_fatal_error(t_env *e)
{
	ft_putendl_fd("ANNILITATION OF THE SOFTWARE", 2);
	ft_putendl_fd("this may have been caused by :", 2);
	ft_putendl_fd("\t\t\t-> An error occuring during the running process", 2);
	ft_putendl_fd("\t\t\t-> Any of the user action.", 2);
	ft_putendl_fd("\t\t\t\tI told you to NOT push the red button", 2);
/*	if (e)
	{
		if (e->img)
		{
			if (e->img->ptr)
				mlx_destroy_image(e->mlx, e->img->ptr);
			free(e->img);
		}
		if (e->win)
		{
			if (e->win->ptr)
				mlx_destroy_window(e->mlx, e->win->ptr);
			free(e->win);
		}
		if (e->mlx)
			free(e->mlx);
		free(e);
	}
*/	exit (0);
}
