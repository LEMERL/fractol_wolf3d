/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 13:24:09 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/17 14:44:25 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void		sh_exit(char **argv, int value)
{
	int		ret;
	int		i;
	int		err;

	if ((err = 0) || value != 42 || argv == NULL)
		ret = value;
	else if ((ret = 0) + 1 && argv && argv[0] && argv[1] != NULL)
	{
		i = 0;
		while (argv[1][i] == '-' || (argv[1][i] != '\0' &&
				ft_isdigit(argv[1][i]) == 1))
			i++;
		if (argv[1][i] != '\0')
			err = 1;
		ret = ft_atoi(argv[1]);
	}
	if (err == 0 && (argv || (argv && argv[0] && argv[1] && argv[2] == NULL)))
	{
		ft_putendl("goodbye, see you soooooon");
		exit(ret);
	}
	ft_putendl("Error: Expression Syntax.\nexit: valid use: exit [value]");
}

static void	sh_env(char **argv, char **env)
{
	char	**tab;

	if (argv[1] == NULL)
		print_env(env);
	else if (argv[1] != NULL && ft_strcmp(argv[1], "-i") == 0)
	{
		tab = (char**)ft_tabnew(2);
		tab[0] = NULL;
		tab[1] = NULL;
		exec_glob(argv + 2, tab);
		free_tab(tab);
	}
	else
		exec_glob(argv + 1, env);
}

int			built_in(char **argv, char **env)
{
	int		i;

	i = 0;
	if (ft_strcmp(argv[0], "exit") == 0 && (i = 1))
		sh_exit(argv, 42);
	else if (ft_strcmp(argv[0], "cd") == 0 && (i = 1))
		sh_cd(argv);
	else if (ft_strcmp(argv[0], "env") == 0 && (i = 1))
		sh_env(argv, env);
	else if (ft_strcmp(argv[0], "setenv") == 0 && (i = 1))
		sh_setenv(argv);
	else if (ft_strcmp(argv[0], "unsetenv") == 0 && (i = 1))
		sh_unsetenv(argv);
	else if (ft_strcmp(argv[0], "help") == 0 && (i = 1))
		sh_help();
	return (i);
}
