/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_path_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 03:48:37 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/08/24 03:56:02 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int			find_short_link_norme(t_list *list, int ret)
{
	while (list != NULL)
	{
		if ((ret == -1 || ret < ((t_salle *)list->content)->dist)
				&& ((t_salle *)list->content)->way_value == 0)
			ret = ((t_salle *)list->content)->dist;
		list = list->next;
	}
	return (ret);
}

t_list		*ret_end(t_list *list)
{
	while (((t_salle *)list->content)->status != END)
		list = list->next;
	return (list);
}
