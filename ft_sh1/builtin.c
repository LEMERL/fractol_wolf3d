/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 13:24:09 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/11 13:33:26 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		built_in(char **argv)
{
	int		i;

	i = 0;
	if (ft_strcmp(argv[0], "exit") == 0 && (i = 1))
	{
		ft_putendl("goodbye, see you soooooon");
		kill(0, 0);
		exit(0);
	}
	else if (ft_strcmp(argv[0], "cd") == 0 && (i = 1))
		sh_cd(argv);
	else if (ft_strcmp(argv[0], "env") == 0 && (i = 1))
		print_env(get_env(NULL, 0));
	else if (ft_strcmp(argv[0], "setenv") == 0 && (i = 1))
		sh_setenv(argv);
	else if (ft_strcmp(argv[0], "unsetenv") == 0 && (i = 1))
		sh_unsetenv(argv);
	return (i);
}


