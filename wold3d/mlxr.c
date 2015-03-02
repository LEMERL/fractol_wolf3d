/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 13:28:31 by mgrimald          #+#    #+#             */
/*   Updated: 2015/02/27 18:21:45 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_img	*mlxr_new_img(t_env *e, int x, int y)
{
	t_img	*img;

	if ((img = (t_img*)malloc(sizeof(t_img))) == NULL)
			exit(0);
	img->width = y;
	img->height = x;
	img->ptr = mlx_new_image(e->mlx, img->width, img->height);
	if (img->ptr == NULL)
		exit(0);
	img->data = mlx_get_data_addr(img->ptr, &(img->bpp),
			&(img->size_line), &(img->endian));
	return (img);
}

int		mlxr_pixel_put_img(t_img *img, int x, int y, int color)
{
	int		octets;
	int		k;

	octets = img->bpp / 8;
	k = img->size_line / octets;
	if ((x >= 0 && x < img->width) && (y >= 0 && y < img->height))
		ft_memcpy(&img->data[octets * (x + k * y)], &color, octets);
	else
		return (-1);
	return (1);
}
