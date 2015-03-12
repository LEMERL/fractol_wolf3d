/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 18:02:51 by mgrimald          #+#    #+#             */
/*   Updated: 2015/03/11 20:25:20 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include "libft/includes/libft.h"

typedef struct		s_lst
{
	int				data;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

typedef int		t_opt;//a changer qd necessaire

int		sw_atoi(char *str);

void	swap_a(t_lst **pile_a, t_opt opt);
void	swap_b(t_lst **pile_b, t_opt opt);
void	swap_f(t_lst **pile_a, t_lst **pile_b, t_opt opt);
void	rotate_a(t_lst **pile_a, t_opt opt);
void	rotate_b(t_lst **pile_b, t_opt opt);

void	push_a(t_lst **pile_a, t_lst **pile_b, t_opt opt);
void	push_b(t_lst **pile_a, t_lst **pile_b, t_opt opt);
void	rotate_f(t_lst **pile_a, t_lst **pile_b, t_opt opt);
void	reverse_rotate_a(t_lst **pile_a, t_opt opt);
void	reverse_rotate_b(t_lst **pile_b, t_opt opt);
void	reverse_rotate_f(t_lst **pile_a, t_lst **pile_b, t_opt opt);

t_lst	*getn_from_start(t_lst *lst, int n);
t_lst	*getn_from_end(t_lst *lst, int n);

#endif
