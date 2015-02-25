/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wlf_get_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:00:58 by mgrimald          #+#    #+#             */
/*   Updated: 2015/02/24 19:50:59 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>
t_struct	***wlf_get_tab(char *old)
{
	t_struct	***tab;
	int			i;
	int			ret;
	char		*str;
	int			fd;
	t_struct	***ptr;

	i = -1;
	fd = open(old, O_RDONLY);
	ptr = NULL;
	while ((++i == 0 || (ptr = tab)) && ((ret = get_next_line(fd, &str)) > 0))
	{
		tab = (t_struct***)malloc(sizeof(t_struct**) * (1 + i));
		ft_memcpy(tab, ptr , (sizeof(t_struct**) * i));
		tab[i] = wlf_strsplit(str, ' ', i);
		free(str);
	}
	if (tab == NULL || ret == -1)
		exit(0);
	printf("x : %d\t%d\ny : %d\t%d\nz = %d\n\n", 3, tab[3][0]->x, 0, tab[3][0]->y, tab[3][0]->z);
	tab[i + 1] = NULL;
	printf("x : %d\t%d\ny : %d\t%d\nz = %d\n\n", 3, tab[3][0]->x, 0, tab[3][0]->y, tab[3][0]->z);
	close(fd);
	return (tab);
}

static int	count_str(char *s, char c)
{
	int			i;
	int			k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			k++;
		i++;
	}
	return (k);
}

t_struct	**wlf_strsplit(char *str, int c, int x)
{
	t_struct	**strc;
	int			i;
	int			j;
	int			k;

	i = 0;
	j = 0;
	k = count_str(str, c);
	if ((strc = (t_struct**)malloc(sizeof(t_struct*) * (k + 1))) == NULL)
		exit(0);
	while (i < k)
	{
		while (str[j] == c && str[j] != '\0')
			j++;
		if ((strc[i] = (t_struct*)malloc(sizeof(t_struct))) == NULL)
			exit(0);
		*(strc[i]) = wlf_get_strc(str + j, x, i);
		ft_putnbr(x);
		ft_putendl("<== oui ceci est degeulasse mais c'est la preuve que mes valeurs sont bonnes");
		ft_putnbr(strc[i]->x);
		ft_putendl("<== et ceci est la confirmation");
		while (str[j] != c && str[j] != '\0')
			j++;
		i++;
	}
	ft_putendl("");
	strc[i] = NULL;
	return(strc);
}
