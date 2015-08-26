/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 06:21:38 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/08/26 16:22:55 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef enum		e_status
{
	BASIC,
	START,
	END,
}					t_status;

typedef struct		s_salle
{
	char			*name;
	int				x;
	int				y;
	int				indice;
	t_status		status;
	int				used;
	int				dist;
	t_list			*link;
	int				way_value;
	int				simple;
}					t_salle;

void				resolve(t_list *list, int ant);
int					get_ant(void);
int					set_ant(int modif);
void				print_list(t_list *list);
void				find_all_path(t_list *list, const int value);
void				omg(t_list *list, int value, int ant);
void				print(t_list *list, int path, int ant);
void				give_value(t_salle *salle);
void				reinit_dist(t_list *list);
void				compute_way(int ant, int *every_path, int len);
void				particular(int *possible, int i, int ant, t_list *list);
void				ft_error(void);
int					find_short_link_norme(t_list *list, int ret);
t_list				*ret_end(t_list *list);
int					lin_parse_comm(char *str, t_status *status);
char				*lin_parse_first(t_list **list);
int					iter_path(t_list *list, int path_length, int ant_v);

#endif
