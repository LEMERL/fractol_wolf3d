/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 18:47:37 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/08/20 19:39:25 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		init_dist(t_list *list)
{
	t_list			*yolo;
	t_salle			*salle;

	yolo = list;
	salle = (t_salle *)yolo->content;
	while (yolo != NULL)
	{
		salle = (t_salle *)yolo->content;
		salle->dist = -1;
		salle->way_value = 0;
		salle->simple = 0;
		yolo = yolo->next;
	}
}

//algo : je passe dans chaque salle pour leur attribuer une valeur depuis l entree

void			give_value(t_salle *salle)
{
	t_list		*link = salle->link;
	t_salle		*test;
	t_list		*temp_link;

	link = salle->link;
	temp_link = link;
//	printf ("\tsalle = %s, salle->value[%d]\n", salle->name, salle->dist);
	while (link != NULL)
	{
		test = (t_salle *)link->content;
//		printf ("\ttest: de dist,test = %s, test->value[%d]\n", test->name, test->dist);
		if (test->dist > salle->dist + 1 || test->dist == -1)
		{
			test->dist = salle->dist + 1;
//			printf ("\t\treassignation de dist,test = %s, test->value[%d]\n", test->name, test->dist);
			give_value(test);
		}
		link = link->next;
	}
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
		//printf ("name [%s], dist[%d]\n", salle->name, salle->dist);
		test = test->next;
	}
}

void			every_path(t_list *list)
{
	t_list			*link;

	ft_putstr ("every_path\n");
	link = list;
	while (((t_salle *)link->content)->status != END)
	{
		link = link->next;
		//printf ("salle de base[%s], valeur de uesd[%d]\n", ((t_salle *)link->content)->name, ((t_salle *)link->content)->dist);
	}
//	printf ("salle de base[%s], valeur de uesd[%d]\n", ((t_salle *)link->content)->name, ((t_salle *)link->content)->dist);
}
void			valid_start(t_list *list)
{
	t_list			*link;
	t_salle			*path;

	path = (t_salle *)list->content;
	link = path->link;
	if (path->link == NULL)
	{
		printf("no link around start\n");
		exit(0);
	}
}

//possibilite de modifier pour effectuer cette operation sur chaque salle en focntion du nom
int			count_possible_path(t_list *list)
{
	t_list		*link;
	t_salle		*path;
	int			ret;

	ret = 0;
	link = list;
	while (((t_salle *)link->content)->status != END)
		link = link->next;
	path = (t_salle *)list->content;
	link = path->link;
	while (link != NULL)
	{
		link = link->next;
		if (link != NULL)
			ret++;
	}
	return (ret);
}

int			possible_path(t_list *list)
{
	t_list		*link;
	static int			debug = 0;

	link = list;
	//printf ("link->name = [%s]\n", ((t_salle *)link->content)->name);
	while (link != NULL && ((t_salle *)link->content)->status != END && debug < 9)
	{
		ft_putendl("boucle\n");
		if (((t_salle *)link->content)->way_value == 0)
		{
			debug++;
			return (0);
		}
	debug++;
		link = link->next;
	}
	return (1);
}

/*int			shortest_path(t_list *list, int value)
{
	t_list			*link;
	t_salle			*path;
	int				choose;
	t_list			*save;

	save = list;
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
			(if (((t_salle *)link)->dist < choose)
			{
				printf ("name = [%s], stauts = [%d], dist[%d], choose [%d]\n", ((t_salle *)link->content)->name, ((t_salle *)link->content)->status, ((t_salle *)link->content)->dist, choose);
				choose = ((t_salle *)link->content)->dist;
			}
			if (((t_salle *)link)->dist < choose)
			{
				choose = ((t_salle *)link->content)->dist;
			}
			link = link->next;
		}
		link = path->link;
		printf ("[%d]\n", choose);
		while (((t_salle *)link->content) != NULL &&((t_salle *)link->content)->dist != choose)
		{
			ft_putstr("\n");
			ft_putstr(((t_salle *)link->content)->name);
			ft_putstr("\n");
			link = link->next;
		}
		path = ((t_salle *)link->content);
		path->way_value = value;
		print_list(save);
		printf("\n%d : %s\n", path->way_value, path->name);
		link = path->link;
	}
	return (1);
}*/
/*
void			shortest_path(t_list *list, int value)
{
	t_list			*link;
	t_salle			*path;
	int				choose;
	int				debug = 0;
	t_list			*full;

	link = list;
	choose = 1000000;
	while (((t_salle *)link->content)->status != END)
		link = link->next;
	path = (t_salle *)link->content;
	link = path->link;
	while (path->status != START)
	{
		path = (t_salle *)link->content;
		full = path->link;
		choose = 1000000;
		while (full != NULL)
		{
			if (((t_salle *)full->content)->dist < choose && ((t_salle *)full->content)->way_value == 0)
				choose = ((t_salle *)full->content)->dist;
			full = full->next;
		}
		link = path->link;
		while (((t_salle *)link->content) != NULL && ((t_salle *)link->content)->dist != choose)
			link = link->next;
		path = ((t_salle *)link->content);
		path->way_value = value;
		link = list;
		while (((t_salle *)link->content)->way_value != value)
			link = link->next; // ca c de la merde
		path = ((t_salle *)link->content);
		printf ("3: choose = [%d], name = [%s]\n", choose, path->name);
		link = path->link;
	//	if (debug == 2)
	//		exit (0);
		debug++;
	}
}*/


void			test_show(t_list *list, int ant)
{
	t_list		*link;
	t_salle		*path;
	char		**sol;

	path = (t_salle *)list->content;
	link = path->link;
	printf ("[%s]\n", path->name);
	sol = (char **)malloc(sizeof(char) * path->dist);// faut que je mette le max
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
	if (path->dist == 1)
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
		loop--;7
	}
}*/
// OMG JE BUG SUR L ALGO D AFFICHAGE

void			resolve(t_list *list, int ant)
{
	int			petit;
	int			value = 1;
	//t_ant		brain = init_ant;

	init_dist(list);
	valid_start(list);
	((t_salle*)list->content)->dist = 0;
	give_value((t_salle*)list->content);
	//get end and check it's value ==> it give back petit && if there is a path
//	print_list(list);
	save_the_perl(list);//big dedi a la belgique libre
	//while (possible_path(list) == 0)
//	{
		find_all_path(list, value);
		ft_putstr("test");
	//	value++;
//	}
//	print_list(list);
//	test_show(list, ant);//retourne un char **
	//display_sol(char**, brain, ant);
//	every_path(list);
}

//need un fix sur give_value je dois pas avoir besoin de le faire 2/3 fois pour que ce soit ok pour toutes les maps
//certaines assignation de valeur fail
//if (end == 1) except case 100% win rate!
// prend les chemins les plus cours trie, (nb fourmi + nb_case -1) = nb coups
// on compare de la facon : nb coups > second_path le plus court
//							(nb coups - taille path) / 2 on recompare si il y a un autre chemin dispo
