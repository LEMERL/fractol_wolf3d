/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_autre.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 18:42:09 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/08 16:55:05 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	**prefabriced_env()
{
	char	**env;

	env = (char**)malloc(sizeof(char*) * 3);
	env[0] = ft_strdup("PATH=/bin:/usr/bin:/usr/sbin");
	env[1] = ft_strdup("LEVEL=1");
	env[2] = NULL;
	return (env);
}

void	print_env(char **env)
{
	int		i;

	i = -1;
	while (env[++i] != NULL)
		ft_putendl(env[i]);
	ft_putstr("\n\n");
}

char	**get_addr_str_env(char *head)
{
	char	**env;
	int		i;

	i = 0;
	env = get_env(NULL, 0);
	return (ft_tabchrstr(env, head, ft_strlen(head)));
}

char	*get_str_env(char *head)
{
	char	**env;
	int		i;
	char	**str;
	char	*tmp;

	i = 0;
	env = get_env(NULL, 0);
	if ((str = ft_tabchrstr(env, head, ft_strlen(head))) == NULL || *str == NULL)
		return ("");
	if ((tmp = ft_strchr(*str, '=')) == NULL)
		return ("");
	return (tmp + 1);
}

char	**get_env(char **env, char action)
{
	static char	**ret = NULL;

	if ((action == 'f' || action == 'r') && ret != NULL)
	{
		free_tab(ret);
		ret = NULL;
	}
	if (ret == NULL && (action == 'r' || action == 's'))
	{
		if ((env == NULL || *env == NULL) && action == 's')
			return (prefabriced_env());
		else if (env != NULL && *env != NULL)
			ret = ft_tabdup(env);
	}
	return (ret);
}
