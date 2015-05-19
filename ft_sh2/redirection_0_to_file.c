/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/17 16:40:14 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/19 21:02:50 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "sh1.h"
#include <fcntl.h>

int redir_to_file(int bol, char **cmd, char *path, char **env)
{
	int			pipefd[2];
	pid_t		cpid;
	char		*buf;
	int			rd;
	int			fd;
	int			pid;

	pid = fork();
	if (pid == 0)
	{
		ft_putendl(*cmd);
		ft_putendl(path);
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
			buf = ft_strnew(1024);
			close(pipefd[1]);
			fd = -1;
			/* Close unused write end */
			if (bol != 0)
				fd = open(path, O_APPEND|O_RDWR, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
			if (fd == -1)
				fd = open(path, O_CREAT|O_RDWR, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
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
			exec_glob(cmd, env);
			close(pipefd[1]);
			/* Reader will see EOF */
			wait(NULL);
			/* Wait for child */
			exit(0);
		}
	}
	wait(NULL);
	return (0);
}
