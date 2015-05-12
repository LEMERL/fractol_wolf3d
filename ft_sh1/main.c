/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 20:43:12 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/12 20:47:52 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int			main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	gestion_signal(0);
	get_env(env, 's');
	ft_putendl("\nWelcome in this basic shell.\nAvaible functionnalities are:");
	ft_putstr("\tbasic built_in : gestion of the environment (set, unset and");
	ft_putstr(" print), deplacement and exit\n\tbasic gestion for a few ");
	ft_putstr("signals (^C, segfaults), (^Z acts as ^C)\n");
	ft_putstr("\texecution avaible of file in and out of the path (.|..|path/");
	ft_putstr("to/exec|exec_in_the_path\n");
	ft_putstr("\tgestion of quotes: ' ' \" \"\n\tgestion of inhibitor \\\n\t");
	ft_putstr("gestion of $ (advanced) and ~ (basic)\n");
	ft_putstr("to exit this shell, please use \"exit\", \nif you are in the ");
	ft_putstr("inability to use it, ^\\ will do the job (please avoid this)\n");
	ft_putendl("Enjoy and have a nice time :-D \n");
	sh_boucle_lecture();
	return (0);
}

void		sh_boucle_lecture(void)
{
	int		ret;
	pid_t	pid;
	char	**argv;

	pid = 1;
	while ((ret = get_next_command(&argv)) > 0)
	{
		gestion_signal(2);
		if (ft_strchr(argv[0], '/') != NULL || built_in(argv) == 0)
		{
			if (argv[0][0] == '.' || ft_strchr(argv[0], '/') != NULL)
				exec_command(argv, argv[0], get_env(NULL, 0));
			else
				command_in_path(argv, get_env(NULL, 0));
		}
		gestion_signal(0);
		wait(NULL);
		free_tab(argv);
	}
}

void		exec_command(char **argv, char *cmd, char **env)
{
	int		i;
	pid_t	pid;
	char	*tmp;

	if ((i = check_file(cmd)) == 1)
	{
		if ((pid = fork()) < 0)
			exit(-1);
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
	}
	else if (i == 2 || i == 0)
		ft_putendl(cmd);
}

void		command_in_path(char **tab_cmd, char **env)
{
	char		*cmd;
	int			j;
	char		**path;

	j = -1;
	if ((path = (char**)get_str_env("PATH")) == NULL)
	{
		ft_putendl("ERROR : THERE IS NO PATH");
		exit (-1);
	}
	cmd = (char*)ft_strnew(ft_strlen((char*)path) + ft_strlen(tab_cmd[0]) + 3);
	path = ft_strsplit((char*)path, ':');
	while (path[++j] != NULL)
	{
		ft_strclr(cmd);
		cmd = ft_strcat(cmd, path[j]);
		cmd = ft_strcat(cmd, "/");
		cmd = ft_strcat(cmd, tab_cmd[0]);
		if (access(cmd, F_OK) == 0)
			break ;
		cmd = ft_strcpy(cmd, tab_cmd[0]);
	}
	exec_command(tab_cmd, cmd, env);
	ft_strdel(&cmd);
	free_tab(path);
}
