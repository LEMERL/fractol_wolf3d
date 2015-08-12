#include "lemin.h"

static void	ft_error(void)
{
	ft_putstr("ERROR\n");
	exit(1);
}

int			lin_parse_comm(char *str, t_status *status)
{
	if (str == NULL || str[0] == '\0' || str[0] == '#')
	{
		if (str && str[0] && str[1] == '#' && ft_strequ(str + 2, "start"))
		{
			if (*status != BASIC)
				ft_error();
			else
				*status = START;
		}
		else if (str && str[0] && str[1] == '#' && ft_strequ(str + 2, "end"))
		{
			if (*status != BASIC)
				ft_error();
			else
				*status = END;
		}
		return (1);
	}
	return (0);
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
	printf("%s\t(%d/%d)\t%d\t%d\n", salle.name, salle.x, salle.y, salle.indice, *status);
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

void		check_list(t_list **alst)
{
	t_list		*tmp;
	int			end_chk;
	int			start_chk;

	end_chk = 0;
	start_chk = 0;
	tmp = *alst;
	while (tmp != NULL)
	{
		if (((t_salle*)tmp->content)->status == END)
			end_chk++;
		else if (((t_salle*)tmp->content)->status == START)
			start_chk++;
		tmp = tmp->next;
	}
	if (end_chk != 1 || start_chk != 1)
		ft_error();
}

int			lim_linker(t_list *tmp, char *str, t_salle *salle)
{
	while (tmp && ft_strequ(str, ((t_salle*)tmp->content)->name) == 0)
		tmp = tmp->next;
	if (tmp == NULL)
		return (-1);
	ft_lstaddcreate(&(salle->link), tmp->content);
	ft_lstaddcreate(&(((t_salle*)tmp->content)->link), salle);
	return (1);
}

void		add_link_list(t_list **alst, char *str)
{
	t_list		*tmp;
	char		**split;
	int			rd;

	rd = 1;
	while (rd > 0)
	{
		split = ft_strsplit(str, '-');
		ft_strdel(&str);
		if (split == NULL || split[0] == NULL || split[1] == NULL
				|| split[2] != NULL || ft_strequ(split[0], split[1]))
			return ;
		tmp = *alst;
		while (tmp && ft_strequ(split[0], ((t_salle*)tmp->content)->name) == 0)
			tmp = tmp->next;
		if (!tmp || lim_linker(*alst, split[1], (t_salle*)tmp->content) == -1)
			return ;
		rd = get_next_line(0, &str);
		free_tab(split);
	}
}

#include <stdio.h>

void	print_list(t_list *list)
{
	t_salle		*salle;
	t_list		*link;

	while (list != NULL)
	{
		salle = (t_salle*)list->content;
		link = salle->link;
		printf("\n\n%s\t(%d/%d)\t%d\t", salle->name, salle->x, salle->y, salle->indice);
		if (salle->status == BASIC)
			printf("BASIC\n");
		else if (salle->status == START)
			printf("START\n");
		else if (salle->status == END)
			printf("END\n");
		while (link != NULL)
		{
			printf("\t%s\n", ((t_salle*)link->content)->name);
			link = link->next;
		}
		list = list->next;
	}
}

int		main(void)
{
	t_list	*list;
	char	*str;

	list = NULL;
	str = lin_parse_first(&list);
	if (str == NULL)
		ft_error();
	check_list(&list);
	add_link_list(&list, str);
	print_list(list);
	return (0);
}
