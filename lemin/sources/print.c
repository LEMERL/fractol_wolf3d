#include "../includes/lemin.h"

static int	follow_path(t_list *list, int path_length)
{
	t_list		*link;
	t_salle		*path;
	int			ret;

	ret = 0;
	path = ((t_salle *)list->content);
	while (path->status != END)
	{
		printf ("name = %s\n", path->name);
		link = path->link;
		while (((t_salle *)link->content)->way_value != path_length)
		{
			printf ("passage, %d\n", ret);
			if (((t_salle *)link->content)->status == END)
				return (ret);
			link = link->next;
		}
		path = ((t_salle *)link->content);
		ret++;
	}
	return (ret);
}

void		print(t_list *list, int path, int ant)
{
	int			*possible;
	int			i;
	int			temp_path;

	printf ("plesase");
	temp_path = 1;
	possible = (int *)malloc(sizeof(int) * path);
	i = 0;
	while (i < path)
	{
		printf ("test");
		possible[i] = follow_path(list, temp_path) + 1;
		temp_path++;
		printf ("possible[%d] = %d\n", i ,possible[i]);
		i++;
	}
	printf ("ok");
	exit (0);
}

//nb + fourmis + nb de case - 1 = nb de coups
// CMP par rapport au second chemin if sup taille de chemin (nb cps - 9) /2)
//
