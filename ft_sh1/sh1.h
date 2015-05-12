/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 14:32:21 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/12 18:34:14 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH1_H
# define SH1_H

#include "libft/includes/libft.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>

void	gestion_signal(int value);
void	sighandler(int);

void	get_command(char **tab_line);

/*env_autre.c*/

char	**prefabriced_env();
char	**get_env(char **env, char action);
//f == free // r == replace // s == start (debut)

char	*get_str_env(char *head);
void	print_env(char **env);
char	**get_addr_str_env(char *head);

void	sh_setenv(char **argv);
void	sh_unsetenv(char **argv);

int			get_next_command(char ***tab_command);
int			sh_prompt(void);

void		sh_cd(char **arg);

char		**split_cmd(char *str);
int			check_file(char *path);

#endif
