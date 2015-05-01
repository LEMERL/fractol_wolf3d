/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 14:32:21 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/01 19:02:46 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH1_H
# define SH1_H

#include "libft/includes/libft.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>


typedef struct		s_env
{
	char			**env;
	char			**path;
	char			*home;
	char			*pwd;
	char			*oldpwd;
}					t_env;

void	gestion_signal();
void	ignore_signal();
void	sighandler(int);

void	get_first_env(char **env, t_env *strc);

void		get_env(t_env *strc_env, char **env);
void		get_command(t_env *strc_env, char **tab_line);

void	free_tab(char **tab);
void	print_env(char **env);
char	**ft_remove_1(char **tab, char *str);
char	**ft_tabadd(char **tab, char *add);
#endif
