/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 20:29:20 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/13 22:59:02 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	signal_in_fork(int value)
{
	ft_putstr("\nCaught signal : ");
	ft_putnbr(value);
	ft_putendl("coming out...");
	ft_putendl("goodbye");
	sh_exit(NULL, value);
}

void	signal_message(int signum)
{
	if (signum == SIGINT)
		ft_putstr("SIGINT: Interupt\n");
	if (signum == SIGTERM)
		ft_putstr("SIGTERM: terminate\n");
	if (signum == SIGFPE)
		ft_putstr("SIGFPE: floating point exeption\n");
	if (signum == SIGABRT)
		ft_putstr("SIGABRT: Abnormal termination\n");
	if (signum == SIGSEGV)
		ft_putstr("SIGSEG: Segmentation violation\n");
	if (signum == SIGTSTP)
		ft_putstr("SIGTSTP: sorry, you are not allowed to do so.\n");
}

void	passif(int value)
{
	(void)value;
	sh_prompt();
}

void	gestion_signal(int value)
{
	void	*ft;

	ft = passif;
	if (value == 1)
		ft = signal_in_fork;
	else if (value == 2)
		ft = signal_message;
	signal(SIGFPE, ft);
	signal(SIGSEGV, ft);
	signal(SIGABRT, ft);
	signal(SIGTERM, ft);
	signal(SIGTSTP, ft);
	signal(SIGINT, ft);
}
