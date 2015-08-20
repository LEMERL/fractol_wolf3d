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
		salle->simple = 0;
		yolo = yolo->next;
	}
}

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

/*	printf ("salle de base %s\n", salle->name);
	while (proc != NULL)
	{
		printf("name = [%s]\n", ((t_salle*)proc->content)->name);
		link_base++;
		proc = proc->next;
	}
	printf ("link_base = [%d]\n", link_base);*/
	salle->used = i;
	while (list != NULL)
	{
		salle = (t_salle*)list->content;
		link = salle->link;
		//str = ft_strcat(salle->name, str);
		if (salle->used <= 100)
			i = salle->used + 1;
		else
			i++;
		//printf ("salle->actuel [%s] valeur[%d]\n", salle->name, salle->used);
		while (link != NULL)
		{
		//	printf ("i = [%d]\n", i);
			test = (t_salle *)link->content;
		//	printf ("test[%s]\n",((t_salle *)list->content)->name);
		//
		//	printf ("\ttest = %s, test->value[%d]\n", test->name, test->used);
			if (test->used > i)
			{
				test->used = i;
		//		printf ("\t\treassignation de used,test = %s, test->value[%d]\n", test->name, test->used);
			}
			if (test->status == END)
			{
				if (petit > test->used)
					petit = test->used;
				bol = 1;
	//			printf ("\nEND\n\t\ttest = %s, test->value[%d]\n", test->name, test->used);
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
		//printf ("name [%s], used[%d]\n", salle->name, salle->used);
		test = test->next;
	}
}

void			every_path(t_list *list)
{
	t_list			*link;

	link = list;
	while (((t_salle *)link->content)->status != END)
	{
		link = link->next;
		//printf ("salle de base[%s], valeur de uesd[%d]\n", ((t_salle *)link->content)->name, ((t_salle *)link->content)->used);
	}
//	printf ("salle de base[%s], valeur de uesd[%d]\n", ((t_salle *)link->content)->name, ((t_salle *)link->content)->used);
}
void			valid_start(t_list *list)
{
	t_list			*link;
	t_salle			*path;

	path = (t_salle *)list->content;
	link = path->link;
	if (path->link == NULL)
	{
		printf ("no link between start and end\n");
		exit (0);
	}
}

void			shortest_path(t_list *list)
{
	t_list			*link;
	t_salle			*path;
	int				choose;

	choose = 1000;
	while (((t_salle *)list->content)->status != END)
		list = list->next;
	path = (t_salle *)list->content;
	link = path->link;
	//printf ("name = [%s], status = [%d]\n", path->name, path->status);
	while (path->status != START)
	{
		while (link != NULL)
		{
		//	ft_putstr("boucle 1\n");
		//	ft_putnbr(((t_salle *)link->content)->used);
			if (((t_salle *)link)->used < choose)
			{
				//ft_putendl(((t_salle *)link->content)->name);
//				printf ("name = [%s], stauts = [%d], used[%d]\n", ((t_salle *)link->content)->name, ((t_salle *)link->content)->status, ((t_salle *)link->content)->used);
				choose = ((t_salle *)link->content)->used;
			}
			link = link->next;
		}
	//	ft_putnbr(choose);
//		exit (0);
/*		ft_putstr("\t\tboucle 2\n\t\t\t");
		ft_putnbr(choose);
		ft_putstr("\n");*/
		link = path->link;
		while (((t_salle *)link->content)->used != choose)
		{
		//	ft_putstr(((t_salle *)link->content)->name);
			link = link->next;
		}
		//ft_putstr("erreur");
	//	ft_putstr(((t_salle *)link->content)->name);
		path = ((t_salle *)link->content);
	//	ft_putstr(((t_salle *)list->content)->name);
		path->way_value = 1;
		link = path->link;
//		printf ("name = [%s], status = [%d]\n", path->name, path->status);
//		exit (0);
	}
}


void			test_show(t_list *list, int ant)
{
	t_list		*link;
	t_salle		*path;
	char		**sol;

	path = (t_salle *)list->content;
	link = path->link;
	printf ("[%s]\n", path->name);
	sol = (char **)malloc(sizeof(char) * path->used);// faut que je mette le max
	//je met tout les noms dedans
	while (path->status != END)
	{
		path->simple = 1;
		while (((t_salle *)link->content)->way_value != 1 && ((t_salle *)link->content)->simple != 0)
		{
			link = link->next;
		}
		path = ((t_salle *)link->content);
		link = path->link;
		printf ("path->name = [%s]\n", path->name);
	}
}

void			save_the_perl(t_list *list)
{
	t_salle				*path;

	path = ((t_salle *)list->content);
	while (path->status != END)
	{
		list = list->next;
		path = (t_salle *)list->content;
	}
	if (path->used == 1)
	{
		//finish_the_game(list);
		printf ("i finished the game\n");
		exit (0);
	}
}

/*void			display_sol(char **path, t_ant *ant, int nb)
{
	int			loop;

	loop = nb;
	while (loop > 0)
	{
		printf ("L[%d]-[%s] ", ant->which_one, path[path->which_room]);
		loop--;
	}
}*/
// OMG JE BUG SUR L ALGO D AFFICHAGE

void			resolve(t_list *list, int ant)
{
	int			petit;
	//t_ant		brain = init_ant;

	init_used(list);
	valid_start(list);
	petit = give_value(list);
//	petit = give_value(list);
//	petit = give_value(list);
	save_the_perl(list);//big dedi a la belgique libre
	shortest_path(list);
	test_show(list, ant);//retourne un char **
	//display_sol(char**, brain, ant);
//	every_path(list);
}

//need un fix sur give_value je dois pas avoir besoin de le faire 2/3 fois pour que ce soit ok pour toutes les maps
//certaines assignation de valeur fail
//if (end == 1) except case 100% win rate!
// prend les chemins les plus cours trie, (nb fourmi + nb_case -1) = nb coups
// on compare de la facon : nb coups > second_path le plus court
//							(nb coups - taille path) / 2 on recompare si il y a un autre chemin dispo
