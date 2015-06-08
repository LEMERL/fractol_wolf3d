/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 06:05:15 by mgrimald          #+#    #+#             */
/*   Updated: 2015/06/08 06:17:29 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		main(int argc, char **argv)
{
	t_env	*env;

	if ((env = (t_env*)ft_strnew(sizeof(t_env))) == NULL)
		ft_fatal_error(env);
	frct_argument(env, argc, argv);
	frct_init(env);
	frct_draw(env);
	frct_mlx(env);
	return (0);
}
