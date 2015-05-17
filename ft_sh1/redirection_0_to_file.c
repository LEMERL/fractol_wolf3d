/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/17 16:40:14 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/17 18:16:23 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "sh1.h"
#include <fcntl.h>

int redirect_to_file(int argc, char **argv)
{
	int			pipefd[2];
	pid_t		cpid;
	char		*buf;
	int			rd;
	int			fd;

	buf = ft_strnew(1024);
	assert(argc == 4);
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
		if (*argv[2] == '0')
			fd = open(argv[3], O_CREAT|O_TRUNC|O_RDWR, S_IRUSR|S_IWUSR|S_IXUSR);
		else
			fd = open(argv[3], O_APPEND | O_RDWR, S_IRUSR|S_IWUSR|S_IXUSR);
		/* Child reads from pipe */
		while ((rd = read(pipefd[0], buf, 1024)) > 0)
			write(fd, buf, rd);
		ft_putendl_fd("\nFINI", fd);
		close(fd);
		close (pipefd[0]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		/* Parent writes argv[1] to pipe */
		close(pipefd[0]);
		/* Close unused read end */
		write(pipefd[1], argv[1], strlen(argv[1]));
		close(pipefd[1]);
		/* Reader will see EOF */
		wait(NULL);
		/* Wait for child */
		exit(EXIT_SUCCESS);
	}
}
