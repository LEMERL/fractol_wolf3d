/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 14:07:41 by mgrimald          #+#    #+#             */
/*   Updated: 2015/05/09 16:09:03 by mgrimald         ###   ########.fr       */
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
	aut = ft_strnew(ft_strlen(ret) + ft_strlen(str + *j) + ft_strlen(get_str_env(tmp)));
	ft_strcpy(aut, ret);
	aut = ft_strcat(aut, get_str_env(tmp));
	free(ret);
	free(tmp);
	ft_putendl(aut);
	*j = *j + k;
	return (aut);
}

char	*ft_fill_tab(char *str, int *j)
{
	char	*ret;
	int		n;

	n = 0;
	if (str[*j] != '\0' && str[*j] == '~')
	{
		ret = ft_strnew(ft_strlen(get_str_env("HOME") + ft_strlen(str + *j)));
		ret = ft_strcpy(ret, get_str_env("HOME"));
		(*j)++;
	}
	else
		ret = ft_strnew(ft_strlen(str + *j));
	while (str[*j] != '\0' && ft_isspace(str[*j]) == 0)
	{
		if (str[*j] == '\\')
			(*j)++;
		else if (str[*j] == '\'' || str[*j] == '"')
			guillemet(str, ret, j, str[*j]);
		else if (str[*j] == '$')
			ret = gestion_dollar(ret, str, j);
		n = ft_strlen(ret);
		ret[n] =  str[(*j)++];
	}
	return (ret);
}

char		**split_cmd(char *str)
{
	char	**tab;
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	tab = (char**)ft_strnew(sizeof(char*) * 1);
	j = 0;
	while (str[j] != '\0')
	{
		while (str[j] != '\0' && ft_isspace(str[j]))
			j++;
		if (str[j] == '\0')
			break ;
		tmp = ft_fill_tab(str, &j);
		if (tmp != NULL)
		{
			tab = ft_tabadd(tab, tmp);
			free(tmp);
		}
	}
	return (tab);
}
