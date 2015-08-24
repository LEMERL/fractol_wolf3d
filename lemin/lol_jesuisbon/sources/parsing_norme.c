/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 02:23:25 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/08/24 06:27:42 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

#define TTC ((t_salle *)tmp->content)
#define TC tmp->content

static int	*loop_tmp(t_list *tmp, int end_chk, int start_chk)
{
	int		*ret;

	ret = (int *)malloc(sizeof(int) * 2);
	while (tmp != NULL)
	{
		if ((((t_salle*)tmp->content)->status == END && end_chk++ == 1) ||
				(((t_salle*)tmp->content)->status == START && start_chk++ == 1))
			ft_error();
		tmp = tmp->next;
	}
	ret[0] = end_chk;
	ret[1] = start_chk;
	return (ret);
}

void			check_list(t_list **alst)
{
	t_list		*tmp;
	t_list		*prev;
	int			*end_start;

	tmp = *alst;
	end_start = (int *)malloc(sizeof(int) * 2);
	end_start = loop_tmp(tmp, 0, 0);
	if (end_start[0] != 1 || end_start[1] != 1)
		ft_error();
	tmp = *alst;
	prev = NULL;
	while (tmp != NULL)
	{
		if (prev != NULL && ((t_salle*)tmp->content)->status == START)
		{
			prev->next = tmp->next;
			tmp->next = *alst;
			*alst = tmp;
			break ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

int				lim_linker(t_list *tmp, char *str, t_salle *salle)
{
	while (tmp && ft_strequ(str, ((t_salle*)tmp->content)->name) == 0)
		tmp = tmp->next;
	if (tmp == NULL)
		return (-1);
	ft_lstaddcreate(&(salle->link), tmp->content);
	ft_lstaddcreate(&(((t_salle*)tmp->content)->link), salle);
	return (1);
}

void			add_link_list(t_list **alst, char *str)
{
	t_list		*tmp;
	char		**split;
	int			rd;

	rd = 1;
	if (str == NULL)
		return ;
	while (rd > 0)
	{
		split = ft_strsplit(str, '-');
		if (lin_parse_comm(str, NULL) == 0)
		{
			if (split == NULL || split[0] == NULL || split[1] == NULL
					|| split[2] != NULL || ft_strequ(split[0], split[1]))
				return ;
			tmp = *alst;
			while (tmp && ft_strequ(split[0], TTC->name) == 0)
				tmp = tmp->next;
			if (!tmp || lim_linker(*alst, split[1], (t_salle*)TC) == -1)
				return ;
		}
		ft_strdel(&str);
		rd = get_next_line(0, &str);
		free_tab(split);
	}
}

int				main(void)
{
	t_list	*list;
	char	*str;
	int		ant;

	ant = get_ant();
	list = NULL;
	str = lin_parse_first(&list);
	if (str == NULL)
		ft_error();
	check_list(&list);
	add_link_list(&list, str);
	resolve(list, ant);
	return (0);
}
