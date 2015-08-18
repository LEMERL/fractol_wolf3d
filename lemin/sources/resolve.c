#include "lemin.h"

static void		init_used(t_list *list)
{
	t_list			*yolo;
	t_salle			*salle;

	yolo = list;
	salle = (t_salle *)yolo->content;
	while (yolo != NULL)
	{
		salle = (t_salle *)yolo->content;
		salle->used = 1000000;
		salle->way_value = 0;
		yolo = yolo->next;
	}
}

/*static void		djikstra(t_list *list)
{
	t_salle			*path;
	t_list			*l;
	t_salle			*next_salle;
	int				i;

	i = 1;
	l = list;
	while (l != NULL)
	{
		path = l->content;
		while (path->link != NULL)
		{
				ft_putstr(path->name);
				ft_putstr("  ");
				ft_putnbr(path->used);
				ft_putstr("\n");
			if (path->used == 0)
				path->used = i;
			path->link = path->link->next;
			if (path->status == END)
			{
				printf ("\ntrouve\n");
				exit (0);
			}
		}
		l = l->next;
		i++;
	}
}*/

/*void			djikstra_good_one(t_list *list)
{
	t_salle			*salle;
	t_list			*link;

	while (list != NULL)
	{
		salle = (t_salle*)list->content;
		link = salle->link;
		printf ("%s salle actuel\n", salle->name);
		while (link != NULL)
		{
			if (salle->used == 1)
				printf ("je suis passe par la\n");
			((t_salle*)link->content)->used = 1;
			printf("name = [%s]\n", ((t_salle*)link->content)->name);
			link = link->next;
		}
		printf ("je change de salle\n");
		list = list->next;
	}
}*/

/*void			random(t_list *list)
{
	t_salle			*salle;
	t_list			*link;

	while (list != NULL)
	{
		salle = (t_salle *)list->content;
		link = salle->link;
		printf ("salle actuel %s\n", salle->name);
		if ()
	}
}*/

//algo : je passe dans chaque salle pour leur attribuer une valeur depuis l entree

int				give_value(t_list *list)
{
	int			i = 0;
	t_salle		*salle = (t_salle*)list->content;
	t_list		*link = salle->link;
	char		*str = (char *)malloc(sizeof(char) * 100000);
	t_salle		*test;
	int			petit = 1000;
	int			bol = 0;
	int			link_base = 0;
	t_list		*proc = link;

	printf ("salle de base %s\n", salle->name);
	while (proc != NULL)
	{
		printf("name = [%s]\n", ((t_salle*)proc->content)->name);
		link_base++;
		proc = proc->next;
	}
	printf ("link_base = [%d]\n", link_base);
	exit (0);
	salle->used = i;
	while (list != NULL)
	{
		salle = (t_salle*)list->content;
		link = salle->link;
		//str = ft_strcat(salle->name, str);
		i = salle->used + 1;
		printf ("salle->actuel [%s] valeur[%d]\n", salle->name, salle->used);
		while (link != NULL)
		{
			printf ("i = [%d]\n", i);
			test = (t_salle *)link->content;
		//	printf ("test[%s]\n",((t_salle *)list->content)->name);
		//
			printf ("\ttest = %s, test->value[%d]\n", test->name, test->used);
			if (test->used >= i )
			{
				test->used = i;
				printf ("\t\treassignation de used,test = %s, test->value[%d]\n", test->name, test->used);
			}
			if (test->status == END)
			{
				if (petit > test->used)
					petit = test->used;
				bol = 1;
				printf ("\nEND\n\t\ttest = %s, test->value[%d]\n", test->name, test->used);
			}
			link = link->next;
		}
	//	printf ("Quit\n");
	//	exit (0);
		list = list->next;
	}
	if (bol == 0)
	{
		printf ("no link between start and end\n");
		exit (0);
	}
	return (petit);
}

void			test(t_list *list)
{
	t_list		*test;
	t_salle		*salle;

	test = list;
	salle = (t_salle *)test->content;
	while (test != NULL)
	{
		salle = (t_salle *)test->content;
		printf ("name [%s], used[%d]\n", salle->name, salle->used);
		test = test->next;
	}
}

/*void			shortest_path(t_list *list, int petit)
{
	t_list		*link;
	t_salle		*salle;
	char		*prev;
	int			comp;

	while (((t_salle *)list->content)->status != END)
		list = list->next;
	prev = (char *)malloc(sizeof(char *) * 99);
	salle = (t_salle *)list->content;
	link = salle->link;
	printf ("salle de base [%s]\n", ((t_salle *)list->content)->name);
	while (((t_salle *)list->content)->status != START)
	{
		comp = (((t_salle *)list->content)->used);
		printf ("salle checker[%s]\n comp = [%d], salle->used[%d]\n", ((t_salle *)list->content)->name, comp, salle->used);
		while (link != NULL)
		{
			if (comp > salle->used)
				comp = salle->used;
			link = link->next;
		}
		link = salle->link;
		while (link != NULL && comp != ((t_salle *)list->content)->used)
			link = link->next;
	}
}*/

void			every_path(t_list *list)
{
	t_list			*link;

	link = list;
	while (((t_salle *)link->content)->status != END)
	{
		link = link->next;
		printf ("salle de base[%s], valeur de uesd[%d]\n", ((t_salle *)link->content)->name, ((t_salle *)link->content)->used);
	}
//	printf ("salle de base[%s], valeur de uesd[%d]\n", ((t_salle *)link->content)->name, ((t_salle *)link->content)->used);
}

void			resolve(t_list *list)
{
	int			petit;
	t_path		*path;

	init_used(list);
//	test(list);
//	random_path(list);
//	djikstra_good_one(list);
	petit = give_value(list);
//	shortest_path(list, petit);
	every_path(list);
}

//if (end == 1) except case 100% win rate!
