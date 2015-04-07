/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 14:32:21 by mgrimald          #+#    #+#             */
/*   Updated: 2015/04/07 16:51:24 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH1_H
# define SH1_H

#include "libft/includes/libft.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>


typedef struct		s_sub_env
{
	char			*full;
	char			*head;
	char			*body;
}					t_sub_env;

typedef struct		s_env
{
	t_list			*list;
	char			**env;
	char			***tab;
	char			**path;
	char			*home;
	char			*pwd;
	char			*oldpwd;
}					t_env;

void	gestion_signal();
void	ignore_signal();
void	sighandler(int);

void		get_env(t_env *strc_env, char **env);
char		**get_command(t_env *strc_env, char **tab_line);

void	free_tab(char **tab);
void	print_env(char **env);
char	**ft_remove_1(char **tab, char *str);
char	**ft_tabadd(char **tab, char *add);
#endif
