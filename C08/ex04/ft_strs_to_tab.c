/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 14:57:43 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/24 19:03:24 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int						ft_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void					ft_copy(char *src, char *str)
{
	int i;

	i = -1;
	while (src[++i])
		str[i] = src[i];
	str[i] = 0;
}

struct	s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	int				i;
	int				len;
	t_stock_str		*t_stock;

	if (!(t_stock = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1))))
		return (NULL);
	i = -1;
	while (++i < ac)
	{
		len = ft_len(av[i]);
		t_stock[i].size = len;
		t_stock[i].str = av[i];
		if (!(t_stock[i].copy = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		ft_copy(av[i], t_stock[i].copy);
	}
	t_stock[i].str = 0;
	return (t_stock);
}
