/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 15:12:33 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/08/18 16:24:01 by aiwanesk         ###   ########.fr       */
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
	t_list			*link;
	int				way_value;
}					t_salle;

typedef struct		s_path
{
	char			*str;
	struct s_path	*next;
}					t_path;

void				resolve(t_list *list);

#endif
