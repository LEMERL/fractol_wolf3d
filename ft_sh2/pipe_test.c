/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/17 16:40:14 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/19 18:26:11 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "sh1.h"
#include <fcntl.h>

void	usable_pipe(char **argv_1, char **argv_2, char **env)
{
	int			pipefd[2];
	pid_t		cpid;
	int			local_fork;

	if ((local_fork = fork()) == 0)
	{
		if (pipe(pipefd) == -1)
			exit(-1);
		if ((cpid = fork()) == -1)
			exit(-1);
		if (cpid == 0)
		{
			close(pipefd[1]);
			dup2(pipefd[0], 0);
			close(pipefd[0]);
			exec_glob(argv_2, env);
			exit(-1);
		}
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		exec_glob(argv_1, env);
		exit(0);
	}
	wait(NULL);
}
