/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 14:29:58 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/09 16:13:18 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		sh_prompt(int v)
{
	if (v == 0)
	{
		ft_putstr(ft_strrchr(get_str_env("PWD"), '/'));
		ft_putstr(" : ");
	}
	return (1);
}

int			get_next_command(char ***tab_command)
{
	int		ret;
	char	*line;
	char	**tmp;

	tmp = (char**)ft_strnew(1 * sizeof(char*));
	while(sh_prompt(0) && (ret = get_next_line(0, &line)) > 0)
	{
		if (line != NULL)
		{
			if (*line != '\0')
			{
				*tab_command = split_cmd(line);
				free(line);
				return (1);
			}
			free(line);
		}
	}
	return (ret);
}
