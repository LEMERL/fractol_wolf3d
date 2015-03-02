/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 10:21:37 by mgrimald          #+#    #+#             */
/*   Updated: 2015/02/28 17:10:54 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WOLF_H
# define WOLF_H

# include "libft/includes/get_next_line.h"
# include "libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct	s_door
{
	int			presence;
	int			close;
	int			x;
	int			y;
}				t_door;

typedef struct	s_struct
{
	int			x;
	int			y;
	int			z;
	t_door		*door;
}				t_struct;

typedef struct	s_img
{
	void		*ptr;
	int			width;
	int			height;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_player
{
	int			x;
	int			y;
	int			width;
	int			height;
	t_img		*img;
}				t_player;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			*img;
	t_player		player;
	t_struct		***tab;
	int				x;
	int				y;
	int				height;
	int				width;
}					t_env;

t_struct	***wlf_get_tab(char *old);
t_struct	wlf_get_strc(char *s, int x, int y);
t_struct	**wlf_strsplit(char *str, int c, int x);

t_img			*mlxr_new_img(t_env *e, int x, int y);
int				mlxr_pixel_put_img(t_img *img, int x, int y, int color);

int				move(t_env *env, int x, int y);
#endif
