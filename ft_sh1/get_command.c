/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 14:29:58 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/16 20:18:54 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static int	unseted_promt(void)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 0;
	if ((str = get_str_env("USER")) != NULL && *str != '\0')
	{
		ft_putstr("\033[1;31m <");
		i = 1;
		ft_putstr(str);
		ft_putstr(">\033[0m");
	}
	if ((str = get_str_env("PWD")) != NULL && *str != '\0')
	{
		if ((tmp = ft_strrchr(str, '/')) != NULL)
		{
			if (tmp[1] != '\0')
				str = tmp + 1;
		}
		ft_putstr("\033[1;33m ");
		i = 1;
		ft_putstr(str);
		ft_putstr("\033[0m ");
	}
	return (i);
}

int			sh_prompt(void)
{
	char	*str;
	int		i;

	ft_putendl("");
	if ((str = get_str_env("SHLVL")) != NULL && *str != '\0')
	{
		ft_putstr("\033[1;36m|");
		ft_putstr(str);
		ft_putstr("|\033[0m ");
	}
	i = 0;
	if ((str = get_str_env("PROMPT_MESS")) != NULL && *str != '\0')
	{
		ft_putstr((str = ft_fill_tab(str, &i, 1)));
		ft_strdel(&str);
	}
	else if (unseted_promt() == 0)
	{
		ft_putstr("\033[1;41;37mY U DO DIS TO ME ? ... ( ` - _- `) ...");
	}
	ft_putstr(" $>\033[0m ");
	return (1);
}

int			get_next_command(char ***tab_command, int fd)
{
	int		ret;
	char	*line;

	while (sh_prompt() && (ret = get_next_line(fd, &line)) > 0)
	{
		if (line != NULL)
		{
			if (fd != 0)
				ft_putendl(line);
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
