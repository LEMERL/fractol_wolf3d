/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 22:30:42 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/20 16:16:09 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include <sys/wait.h>

void		usable_pipe(char **argv_1, char **argv_2, char **env);
int			redir_to_file(int bol, char **cmd, char *path, char **env);

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

void	boucle_exec(char **argv)
{
	int		select;
	int		i;

	if (argv == NULL || argv[0] == NULL)
	{
		ft_putendl("syntax error");
		exit(-1);
	}
	select = 0;
	i = 0;
	while (select == 0 && argv[++i] != NULL)
	{
		if (argv[i][0] == ';')
			select = 1;
		else if ((argv[i][0]) == '|')
			select = 2;
		else if ((argv[i][0]) == '>')
		{
			select = 3;
			if (argv[i][1] == '>')
				select = 4;
		}
		else if (argv[i][0] == '<')
		{
			select = 5;
			if (argv[i][1] == '<')
				select = 6;
		}
	}
	char	*tmp;

	if (select != 0)
	{
		tmp = argv[i];
		argv[i] = NULL;
		if (select == 1)
			usable_pipe(argv, argv + i + 1, get_env(NULL, 0));
		if (select == 2)
			redir_to_file(0, argv, argv[i + 1], get_env(NULL, 0));
		if (select == 3)
			redir_to_file(1, argv, argv[i + 1], get_env(NULL, 0));
		argv[i] = tmp;
	}
	else
		exec_glob(argv, get_env(NULL, 0));
}

void		sh_boucle_lecture(int fd)
{
	int		ret;
	char	**argv;

	while ((ret = get_next_command(&argv, fd)) > 0)
	{
		boucle_exec(argv);
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
	if ((i = check_file(cmd, 1)) == 1)
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
