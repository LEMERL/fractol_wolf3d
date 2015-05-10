/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 14:29:58 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/10 18:03:22 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		sh_prompt(int v)
{
	char	*str;
	char	*tmp;

	if (v == 0)
	{
		if ((str = get_str_env("PROMPT_MESS")) != NULL && *str != '\0')
			ft_putstr(str);
		else if ((str = get_str_env("PWD")) != NULL && *str != '\0')
		{
			if ((tmp = ft_strrchr(str, '/')) != NULL)
			{
				if (tmp[1] != '\0')
					str = tmp + 1;
			}
			ft_putstr(str);
		}
		else if ((str = get_str_env("USER")) != NULL && *str != '\0')
			ft_putstr(str);
		else
			ft_putstr("Y U DO DIS ? (╯°□°）╯︵ ┻━┻-");
		ft_putstr(" : ");
	}
	return (1);
}

int			get_next_command(char ***tab_command)
{
	int		ret;
	char	*line;

	while(sh_prompt(0) && (ret = get_next_line(0, &line)) > 0)
	{
		if (line != NULL)
		{
			if (*line != '\0' && (*tab_command = split_cmd(line)) != NULL)
			{
				ft_strdel(&line);
				return (1);
			}
			else
				ft_strdel(&line);
		}
	}
	return (ret);
}
