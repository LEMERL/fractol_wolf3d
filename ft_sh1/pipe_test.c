/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/17 16:40:14 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/17 20:03:38 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "sh1.h"
#include <fcntl.h>

int usable_pipe(char **argv_1, char **argv_2, char **env)
{
	int			pipefd[2];
	pid_t		cpid;
	int			retour;

	retour = -1;
	if (pipe(pipefd) == -1)
		exit(EXIT_FAILURE);
	if ((cpid = fork()) == -1)
		exit(EXIT_FAILURE);
	if (cpid == 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		close(pipefd[0]);
		exec_glob(argv_2, env);
		exit(retour);
	}
	close(pipefd[0]);
	dup2(pipefd[1], 1);
	close(pipefd[1]);
	exec_glob(argv_1, env);
	wait(NULL);
	exit (retour);
}
