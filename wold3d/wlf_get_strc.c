/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wlf_get_strc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 14:28:09 by mgrimald          #+#    #+#             */
/*   Updated: 2015/02/24 15:49:28 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_struct	wlf_get_strc(char *s, int x, int y)
{
	t_struct	strc;

	strc.x = x;
	strc.y = y;
	if (ft_strcmp(s, "D") == 0)
	{
		if ((strc.door = (t_door*)malloc(sizeof(t_door))) == NULL)
			exit(0);
		strc.door->presence = 1;
		strc.door->close = 1;
		strc.door->x = x;
		strc.door->y = y;
		s++;
	}
	strc.z = ft_atoi(s);
	return (strc);
}
