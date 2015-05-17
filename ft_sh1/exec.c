/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 22:30:42 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/17 14:51:37 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include <sys/wait.h>

void		exec_glob(char **argv, char **env)
{
	if (argv != NULL && argv[0] != NULL)
		if (ft_strchr(argv[0], '/') != NULL || built_in(argv, env) == 0)
		{
			if (argv[0][0] == '.' || ft_strchr(argv[0], '/') != NULL)
				exec_command(argv, argv[0], env);
			else
				command_in_path(argv, env);
		}
}

void		sh_boucle_lecture(int fd)
{
	int		ret;
	char	**argv;

	while ((ret = get_next_command(&argv, fd)) > 0)
	{
		exec_glob(argv, get_env(NULL, 0));
		free_tab(argv);
	}
}

static void	exec_itself(char **argv, char *cmd, char **env)
{
	pid_t	pid;
	char	*tmp;
	int		i;

	gestion_signal(3);
	if ((pid = fork()) < 0)
	{
		ft_putendl("Crash of the FORK, EXIT");
		exit(-1);
	}
	else if (pid == 0)
	{
		tmp = argv[0];
		argv[0] = cmd;
		gestion_signal(1);
		if ((i = execve(cmd, argv, env)) == -1)
			ft_putstr("~<-|EXEC ERROR|->~");
		argv[0] = tmp;
		exit(i);
	}
	wait(NULL);
	gestion_signal(0);
}

void		exec_command(char **argv, char *cmd, char **env)
{
	int		i;

	if (cmd == NULL)
		cmd = *argv;
	if ((i = check_file(cmd)) == 1)
		exec_itself(argv, cmd, env);
	else if (i == 3)
	{
		ft_putstr(cmd);
		ft_putendl(": is a symboling link");
	}
	else if (i == 2)
	{
		ft_putstr(cmd);
		ft_putendl(": is a directory");
	}
	else if (i == 0)
	{
		ft_putstr(cmd);
		ft_putendl(": is not an executable file");
	}
}
