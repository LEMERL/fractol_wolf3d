/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 18:55:52 by mgrimald          #+#    #+#             */
/*   Updated: 2015/03/17 14:02:59 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	sw_swap_data(t_lst *a, t_lst *b)
{
	int		tmp;

	tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}


void	reverse_rotate(t_lst **pile_a)
{
	t_lst	*tmp;
	t_lst	*other;

	tmp = getn_from_end(*pile_a, 0);
	if (tmp->prev)
		tmp->prev->next = NULL;
	tmp->next = NULL;
	tmp->prev = NULL;
	other = getn_from_start(*pile_a, 0);
	if (other != tmp)
	{
		tmp->next = other;
		other->prev = tmp;
	}
}

void	reverse_rotate_a(t_lst **pile_a, t_opt opt)
{
	(void)opt;
	reverse_rotate(pile_a);
}

void	reverse_rotate_b(t_lst **pile_b, t_opt opt)
{
	(void)opt;
	reverse_rotate(pile_b);
}

void	reverse_rotate_f(t_lst **pile_a, t_lst **pile_b, t_opt opt)
{
	(void)opt;
	reverse_rotate(pile_a);
	reverse_rotate(pile_b);
}

void	rotate(t_lst **pile_a)
{
	t_lst	*tmp;
	t_lst	*other;

	tmp = getn_from_start(*pile_a, 0);
	if (tmp->next)
		tmp->next->prev = NULL;
	tmp->next = NULL;
	tmp->prev = NULL;
	other = getn_from_end(*pile_a, 0);
	if (other != tmp)
	{
		tmp->prev = other;
		other->next = tmp;
	}
}

void	rotate_a(t_lst **pile_a, t_opt opt)
{
	(void)opt;
	rotate(pile_a);
}

void	rotate_b(t_lst **pile_b, t_opt opt)
{
	(void)opt;
	rotate(pile_b);
}

void	rotate_f(t_lst **pile_a, t_lst **pile_b, t_opt opt)
{
	(void)opt;
	rotate(pile_a);
	rotate(pile_b);
}

void	swap_a(t_lst **pile_a, t_opt opt)
{
	(void)opt;
	sw_swap_data(getn_from_start(*pile_a, 0), getn_from_end(*pile_a, 0));
}

void	swap_b(t_lst **pile_b, t_opt opt)
{
	(void)opt;
	sw_swap_data(getn_from_start(*pile_b, 0), getn_from_end(*pile_b, 0));
}

void	swap_f(t_lst **pile_a, t_lst **pile_b, t_opt opt)
{
	(void)opt;
	sw_swap_data(getn_from_start(*pile_a, 0), getn_from_end(*pile_a, 0));
	sw_swap_data(getn_from_start(*pile_b, 0), getn_from_end(*pile_b, 0));
}
