/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 06:05:15 by mgrimald          #+#    #+#             */
/*   Updated: 2015/07/31 20:27:03 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#include <signal.h>

void	start(int argc, char **argv)
{
	t_env	*e;

	if ((e = (t_env*)ft_strnew(sizeof(t_env))) == NULL)
		ft_fatal_error(e);
	frct_argument(e, argc, argv);
	e->win = (t_win*)ft_strnew((sizeof(t_win)));
	e->mlx = mlx_init();
	if (e->mlx == NULL || e->win == NULL)
		ft_fatal_error(e);
	e->win->width = 1000;
	e->win->height = 1000;
	e->win->ptr = mlx_new_window(e->mlx, e->win->width,
			e->win->height, argv[argc - 1]);
	if (e->win->ptr == NULL)
		ft_fatal_error(e);
	frct_init(e, e->slc);
	frct_draw(e);
	frct_mlx(e);
}

void	sign_hand(int signnum)
{
	(void)signnum;
	wait4(0, 0, WNOHANG, 0);
}

void	forking(int argc, char **argv)
{
	pid_t	pid;

	signal(SIGCHLD, sign_hand);
	pid = 1;
	if (argc > 2 && (pid = fork()) < 0)
		exit(0);
	if (pid == 0)
	{
		forking(argc - 1, argv);
		ft_fatal_error(0);
	}
	else
	{
		start(argc, argv);
		ft_fatal_error(0);
	}
}

int		main(int argc, char **argv)
{
	if (argc <= 2)
		start(argc, argv);
	else
		forking(argc, argv);
	return (0);
}
