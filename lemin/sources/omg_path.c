#include "../includes/lemin.h"

#define CNT ((t_salle *)link->content)

static t_salle	*is_path(t_salle *salle, int value)
{
	int			ret;
	t_list		*link;
	t_salle		*temp;

	link = salle->link;
	ret = -1;
	salle->way_value = value;
	while (link != NULL)
	{
		if (ret == -1 || (ret > (CNT)->dist && CNT->way_value == 0))
		{
			temp = CNT;
			ret = (CNT)->dist;
		}
		link = link->next;
	}
	return (temp);
}

void		omg(t_list *list, int value)
{
	t_list		*link;
	t_salle		*path;

	value = 1; //test
	link = list;
	while (((t_salle *)link->content)->status != END)
		link = link->next;
	path = CNT;
	while (path->status != START)
	{
		path = is_path(path, value);
	}
	print_list(list);
}
