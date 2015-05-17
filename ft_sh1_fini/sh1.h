/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 14:32:21 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/17 14:47:56 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH1_H
# define SH1_H

# include "libft/includes/libft.h"

void	exec_glob(char **argv, char **env);
void	sh_increase_shlvl(void);
void	gestion_signal(int value);
void	sighandler(int signum);
void	sh_exit(char **argv, int value);
void	get_command(char **tab_line);

char	**prefabriced_env(void);
char	**get_env(char **env, char action);
void	sh_help(void);
char	*get_str_env(char *head);
void	print_env(char **env);
char	**get_addr_str_env(char *head);

void	sh_setenv(char **argv);
void	sh_unsetenv(char **argv);

int		get_next_command(char ***tab_command, int fd);
int		sh_prompt(void);
void	sh_cd(char **arg);

char	**split_cmd(char *str);
int		check_file(char *path);
char	*ft_fill_tab(char *str, int *j, int space);

void	sh_fatal_error(char *msg);
int		built_in(char **argv, char **env);
void	sh_boucle_lecture();
void	exec_command(char **argv, char *cmd, char **env);
void	command_in_path(char **tab_cmd, char **env);

#endif
