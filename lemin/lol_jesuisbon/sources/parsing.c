/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 02:23:25 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/08/26 16:30:42 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int			lin_parse_comm(char *str, t_status *status)
{
	if (str == NULL || str[0] == '\0' || str[0] == '#')
	{
		if (str && str[0] && str[1] == '#' && ft_strequ(str + 2, "start"))
		{
			if (status == NULL || *status != BASIC)
				ft_error();
			else
				*status = START;
		}
		else if (str && str[0] && str[1] == '#' && ft_strequ(str + 2, "end"))
		{
			if (status == NULL || *status != BASIC)
				ft_error();
			else
				*status = END;
		}
		return (1);
	}
	return (0);
}

int			set_ant(int modif)
{
	static int	number = -42;
	char		*str;
	char		**tab;
	int			rd;

	if (number == -42)
	{
		ft_putendl("before gnl");
		while ((rd = get_next_line(0, &str)) != 0 || rd == 0)
		{
			ft_putendl("in loop gnl");
			if (rd <= 0 || (tab = ft_strsplit(str, ' ')) == NULL
					|| tab[0] == NULL || (ft_isnumber(tab[0]) == 0
						&& lin_parse_comm(tab[0], NULL) == 0) || tab[1] != NULL)
				ft_error();
			ft_strdel(&str);
			if (ft_isnumber(tab[0]) == 1)
				break ;
			free_tab(tab);
		}
		number = ft_atoi(tab[0]);
		free_tab(tab);
	}
	else
		number -= modif;
	ft_putendl("after gnl");
	return (number);
}

int			get_ant(void)
{
	return (set_ant(0));
}

static void	lin_parse_fill(t_status *status, char **split, t_list **list)
{
	static int	n = 0;
	t_salle		salle;

	ft_bzero((void*)&salle, sizeof(t_salle));
	salle.name = ft_strdup(split[0]);
	salle.status = *status;
	salle.x = ft_atoi(split[1]);
	salle.y = ft_atoi(split[2]);
	salle.indice = n;
	n++;
	ft_lstaddnew(list, (void*)&salle, sizeof(t_salle));
	*status = BASIC;
}

char		*lin_parse_first(t_list **list)
{
	char		*str;
	t_status	status;
	char		**split;

	status = BASIC;
	while ((split = NULL) || get_next_line(0, &str) > 0)
	{
		if (!lin_parse_comm(str, &status) && (split = ft_strsplit(str, ' ')) &&
				split[0])
		{
			if (!split || !split[0] || (!split[1] && status != BASIC))
				ft_error();
			if (split[1] == NULL)
				return (str);
			if ((split[2] == NULL || split[3] != NULL)
					|| !ft_isnumber(split[1]) || !ft_isnumber(split[2]))
				ft_error();
			lin_parse_fill(&status, split, list);
		}
		free_tab(split);
		ft_strdel(&str);
	}
	return (NULL);
}
