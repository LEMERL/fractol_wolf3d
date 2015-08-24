#include "../includes/lemin.h"

static int	follow_path(t_list *list, int path_length)
{
	t_list		*link;
	t_salle		*path;
	int			ret;

	ret = -1;
	path = ((t_salle *)list->content);
	link = path->link;
	while (path->status != END  && ++ret)
	{
		link = path->link;
		while (1)
		{
			if (link == NULL || link->content == NULL || ((t_salle *)link->content)->status == END)
				return (ret);
			if (((t_salle *)link->content)->way_value == path_length && ((t_salle *)link->content)->dist >= path->dist)
				break ;
			link = link->next;
			if (link == NULL || link->content == NULL || ((t_salle *)link->content)->status == END)
				return (0);
		}
		path = ((t_salle *)link->content);
		if (path->status == END)
			return (ret);
		//ret++;
	}
	return (ret);
}

void		print(t_list *list, int path, int ant)
{
	int			*possible;
	int			i;
	int			temp_path;

	temp_path = 1;
	possible = (int *)malloc(sizeof(int) * path);
	i = 0;
	while (i < path)
	{
		possible[i] = follow_path(list, temp_path) + 1;
		temp_path++;
		printf ("possible[%d] = %d\n", i ,possible[i]);
		i++;
	}
	if (possible[0] == 0)
		ft_error();
	if (i > 1)
	{
		particular(possible, i, ant, list);
		exit (0);
	}
	compute_way(ant, possible, i);
}

//nb + fourmis + nb de case - 1 = nb de coups
// CMP par rapport au second chemin if sup taille de chemin (nb cps - 9) /2)
//
