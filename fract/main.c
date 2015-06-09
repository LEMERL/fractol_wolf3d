/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 06:05:15 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/09 15:39:24 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		main(int argc, char **argv)
{
	t_env	*e;

	if ((e = (t_env*)ft_strnew(sizeof(t_env))) == NULL)
		ft_fatal_error(e);
	frct_argument(e, argc, argv);
	e->win = (t_win*)ft_strnew((sizeof(t_win)));
	e->mlx = mlx_init();
	if (e->mlx == NULL || e->win == NULL)
		ft_fatal_error(e);
	e->win->width = 1000;
	e->win->height = 1000;
	e->win->ptr = mlx_new_window(e->mlx, e->win->width, e->win->height, "frct");
	if (e->win->ptr == NULL)
		ft_fatal_error(e);
	frct_init(e, e->slc);
	frct_draw(e);
	frct_mlx(e);
	return (0);
}
