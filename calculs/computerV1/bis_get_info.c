/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bis_get_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 17:43:16 by mgrimald          #+#    #+#             */
/*   Updated: 2015/03/23 17:53:56 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef double t_num;

t_num	ft_atonum(char *str)
{
	int		nbr;
	t_num	deci;
	int		sign;
	int		i;

	nbr = 0;
	sign = 1;
	i = 0;
	deci = 0.0;
	while (str[i] != '\0' && (str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
				|| str[i] == '\v' || str[i] == '\f' || str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + str[i++] - '0';
	if (str[i++] == '.')
	{
		while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
			i++;
		while (str[i] != '.')
			deci = deci / 10 + str[i--] - '0';
	}
	return (((t_num)nbr + deci / 10) * sign);
}

void		tab(char *str, t_stc *a)
{
	int		i;
	int		sign;
	t_num	tmp;

	i = 0;
	sign = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
		{
			sign = -1;
			i++;
		}
		if (str[i] && str[i] >= '0' && str[i] <= '9')
		{
			tmp = ft_atonum(str);

		}
		i++;
	}
}
