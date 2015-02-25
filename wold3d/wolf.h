/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 10:21:37 by mgrimald          #+#    #+#             */
/*   Updated: 2015/02/24 15:19:30 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WOLF_H
# define WOLF_H

# include "libft/includes/get_next_line.h"
# include "libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

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

t_struct	***wlf_get_tab(char *old);
t_struct	wlf_get_strc(char *s, int x, int y);
t_struct	**wlf_strsplit(char *str, int c, int x);

#endif
