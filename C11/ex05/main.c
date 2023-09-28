/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:08:18 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/28 16:41:10 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int		ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while ((str1[i] || str2[i]) && (str1[i] == str2[i]))
		i++;
	return (str1[i] - str2[i]);
}

int		ft_what_op(char *str)
{
	if (!ft_strcmp(str, "+"))
		return (0);
	if (!ft_strcmp(str, "-"))
		return (1);
	if (!ft_strcmp(str, "*"))
		return (2);
	if (!ft_strcmp(str, "/"))
		return (3);
	if (!ft_strcmp(str, "%"))
		return (4);
	return (-214748648);
}

void	ft_fill_tab(int (**ft)(int, int, int *))
{
	ft[0] = &ft_plus;
	ft[1] = &ft_minus;
	ft[2] = &ft_times;
	ft[3] = &ft_divided;
	ft[4] = &ft_modulo;
}

int		ft_atoi(char *str)
{
	int i;
	int nb;
	int pos;

	i = 0;
	nb = 0;
	pos = 1;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			pos *= -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb * pos);
}

int		main(int ac, char **av)
{
	int (*ft[5])(int, int, int *);
	int a;
	int b;
	int i;

	if (ac != 4)
		return (0);
	if (ft_strcmp(av[2], "+") && ft_strcmp(av[2], "-") && ft_strcmp(av[2], "*")
			&& ft_strcmp(av[2], "/") && ft_strcmp(av[2], "%"))
	{
		write(1, "0\n", 2);
		return (0);
	}
	ft_fill_tab(ft);
	a = ft_atoi(av[1]);
	b = ft_atoi(av[3]);
	i = ft_what_op(av[2]);
	ft_doop(a, ft[i], b);
	return (0);
}
