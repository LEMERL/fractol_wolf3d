/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 18:47:37 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/08/24 03:35:02 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		reinit_dist(t_list *list)
{
	t_list			*yolo;
	t_salle			*salle;

	yolo = list;
	salle = (t_salle *)yolo->content;
	while (yolo != NULL)
	{
		salle = (t_salle *)yolo->content;
		if (salle->way_value == 0)
		{
			salle = (t_salle *)yolo->content;
			salle->dist = -1;
			salle->way_value = 0;
			salle->simple = 0;
		}
		yolo = yolo->next;
	}
}
