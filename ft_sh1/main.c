/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 20:43:12 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/17 13:51:02 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include <fcntl.h>

void		sh_help(void)
{
	ft_putendl("Avaible functionnalities are:");
	ft_putstr("\tbasic built_in : gestion of the environment (set, unset and");
	ft_putstr(" print), and deplacement\n\tbasic catching of a few ");
	ft_putstr("signals during execution of external executable");
	ft_putstr(" time.\n\texecution avaible of file in and out of the path ");
	ft_putstr("(.|..|path/to/exec|exec_in_the_path)\n");
	ft_putstr("\tgestion of quotes: ' ' \" \"\n\tgestion of inhibitor \\\n\t");
	ft_putstr("gestion of $ (advanced) and ~\n");
	ft_putstr("\tPROMPT_MESS can be set as a personalised prompt ");
	ft_putstr("(gestion of '$' inside itself avaible)\n");
	ft_putstr("to exit this shell, please use \"exit\"\n");
	ft_putendl("you can also execute it with a file. as 'sh file.sh'");
	ft_putendl("\"env -i cmd\" executes the command in an empty environment");
	ft_putendl("Enjoy and have a nice time :-D \n");
	ft_putendl("nb: you can find back this notice with the command 'help'");
}

int			main(int argc, char **argv, char **env)
{
	int		fd;

	gestion_signal(0);
	get_env(env, 's');
	sh_increase_shlvl();
	fd = 0;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else if (argc > 2)
		ft_putendl("Sorry, too many files to handle. Only one at a time");
	else
	{
		ft_putendl("Welcome in this basic shell.");
		sh_help();
	}
	if (fd >= 0)
	{
		sh_boucle_lecture(fd);
		close(fd);
	}
	else
		ft_putendl("An error occured: Could not open the file");
	return (0);
}

static void	try_path(char **path, char *cmd, char **tab_cmd, char **env)
{
	int		j;

	j = -1;
	while (path[++j] != NULL)
	{
		ft_strclr(cmd);
		cmd = ft_strcat(cmd, path[j]);
		cmd = ft_strcat(cmd, "/");
		cmd = ft_strcat(cmd, tab_cmd[0]);
		if (access(cmd, F_OK) == 0)
			break ;
	}
	if (path[j] == NULL)
	{
		ft_putstr("Command not found :");
		ft_putendl(tab_cmd[0]);
	}
	else
		exec_command(tab_cmd, cmd, env);
}

void		command_in_path(char **tab_cmd, char **env)
{
	char		*cmd;
	char		**path;

	if ((path = (char**)get_str_env("PATH")) == NULL || *path == '\0')
	{
		ft_putendl("ERROR : THERE IS NO PATH");
		return ;
	}
	cmd = (char*)ft_strnew(ft_strlen((char*)path) + ft_strlen(tab_cmd[0]) + 3);
	path = ft_strsplit((char*)path, ':');
	try_path(path, cmd, tab_cmd, env);
	ft_strdel(&cmd);
	free_tab(path);
}
