/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/17 16:40:14 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/17 18:55:17 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "sh1.h"
#include <fcntl.h>

int usable_pipe(int argc, char **argv)
{
	int			pipefd[2];
	pid_t		cpid;
	char		*buf;
	int			rd;
	int			fd;

	buf = ft_strnew(1024);
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	cpid = fork();
	if (cpid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (cpid == 0)
	{
		close(pipefd[1]);
		/* Close unused write end */
		dup2(pipefd[0], 0);
		close(pipefd[0]);
		execlp("cat", "cat", (char *) 0);
		exit(EXIT_SUCCESS);
	}
	else
	{
		/* Parent writes argv[1] to pipe */
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		/* Close unused read end */
		execlp("ls", "ls", (char *)0);
		//will see EOF */
		wait(NULL);
		/* Wait for child */
		exit(EXIT_SUCCESS);
	}
}
