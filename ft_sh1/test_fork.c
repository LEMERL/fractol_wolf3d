/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 16:46:19 by mgrimald          #+#    #+#             */
/*   Updated: 2015/04/02 13:54:51 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int		main(int argc, char **argv, char **env)
{
	pid_t		pid;
	pid_t		sec_pid;
	int			status;

	printf("pre-test : \n");
	pid  = fork();
	if (pid > 0)
	{
		sec_pid = wait(&status);
		printf("0 < pid : father\n");
		printf("pid : %d, \nsec_pid : %d, \nwait-status : %d\n", pid, sec_pid, status);
	}
	if (pid == 0)
	{
		printf("pid == 0 ==> son\n");
		printf("pid : %d, \nsec_pid : %d, \nwait-status : %d\n", pid, sec_pid, status);
		return (-1);
	}
	return (0);
}
