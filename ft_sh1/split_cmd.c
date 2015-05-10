/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 14:07:41 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/10 19:36:06 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	guillemet(char *str, char *ret, int *j, char c)
{
	int		i;

	i = ft_strlen(ret) - 1;
	while (str[*j] != '\0' && str[++(*j)] != c && str[*j] != '\0')
	{
		if (str[*j] == 92)
			(*j)++;
		ret[++i] = str[*j];
	}
	if (str[*j] != '\0')
		(*j)++;
}

char	*gestion_dollar(char *ret, char *str, int *j)
{
	int		k;
	char	*tmp;
	char	*aut;

	(*j)++;
	k = 0;
	while (ft_isalnum(str[*j + k]))
		k++;
	if (k == 0)
	{
		ret[ft_strlen(ret)] = '$';
		return (ret);
	}
	tmp = ft_strndup(str + *j, k - 1);
	aut = ft_strnew(ft_strlen(ret) + ft_strlen(str + *j) + ft_strlen(get_str_env(tmp)) + 3);
	aut = ft_strcpy(aut, ret);
	aut = ft_strcat(aut, get_str_env(tmp));
	ft_strdel(&ret);
	ft_strdel(&tmp);
	ft_putendl(aut);
	*j = *j + k;
	return (aut);
}

char	*gestion_tilde(char *str, int *j)
{
	char	*ret;
	char	*tmp;

	ret = NULL;
	if (str[*j] != '\0' && str[*j] == '~')
	{
		tmp = get_str_env("HOME");
		if (tmp == NULL || *tmp == '\0')
		{
			ft_putendl("variable d'environment \"HOME\" not set");
			return (NULL);
		}
		ret = ft_strnew(ft_strlen(tmp) + ft_strlen(str + *j));
		ret = ft_strcpy(ret, tmp);
		(*j)++;
	}
	else if (str[*j] != '\0')
		ret = ft_strnew(ft_strlen(str + *j));
	return (ret);
}

char	*ft_fill_tab(char *str, int *j)
{
	char	*ret;

	ret = gestion_tilde(str, j);
	if (ret == NULL)
		*j = -1;
	while (ret && str[*j] != '\0' && ft_isspace(str[*j]) == 0)
	{
		if (str[*j] == '\\')
			(*j)++;
		else if (str[*j] == '\'' || str[*j] == '"')
		{
			guillemet(str, ret, j, str[*j]);
			continue ;
		}
		else if (str[*j] == '$')
		{
			ret = gestion_dollar(ret, str, j);
			continue ;
		}
		ret[ft_strlen(ret)] = str[(*j)++];
	}
	return (ret);
}

char		**split_cmd(char *str)
{
	char	**tab;
	int		j;
	char	*tmp;
	char	**t;

	tab = NULL;
	j = 0;
	while (j >= 0 && str[j] != '\0')
	{
		while (str[j] != '\0' && ft_isspace(str[j]))
			j++;
		if (str[j] == '\0')
			break ;
		tmp = ft_fill_tab(str, &j);
		if ((t = NULL) || tmp != NULL)
			t = ft_tabadd(tab, tmp);
		if (tmp != NULL || j == -1)
		{
			free_tab(tab);
			tab = t;
			ft_memdel((void**)&tmp);
		}
	}
	return (tab);
}
