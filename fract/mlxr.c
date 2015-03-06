/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 13:28:31 by mgrimald          #+#    #+#             */
/*   Updated: 2015/03/02 17:02:26 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	mlxr_new_img(t_env *e)
{
	if (e->img != NULL && e->img->ptr != NULL)
			mlx_destroy_image(e->mlx, e->img->ptr);
	else if ((e->img = (t_img*)malloc(sizeof(t_img))) == NULL)
			ft_fatal_error(e);
	e->img->width = e->win->width;
	e->img->height = e->win->height;
	e->img->ptr = mlx_new_image(e->mlx, e->img->width, e->img->height);
	if (e->img->ptr == NULL)
		ft_fatal_error(e);
	e->img->data = mlx_get_data_addr(e->img->ptr, &(e->img->bpp),
			&(e->img->size_line), &(e->img->endian));
}

int		mlxr_pixel_put_img(t_env *e, int x, int y, int color)
{
	t_img	*img;
	int		octets;
	int		k;

	img = e->img;
	octets = img->bpp / 8;
	k = img->size_line / octets;
	if ((x >= 0 && x < img->width) && (y >= 0 && y < img->height))
		ft_memcpy(&img->data[octets * (x + k * y)], &color, octets);
	else
		return (-1);
	e->img = img;
	return (1);
}
