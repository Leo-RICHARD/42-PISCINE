/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:01:21 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/25 11:34:05 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	long long int	i;
	long long int	range;
	int				*tab;

	if (max <= min)
	{
		tab = NULL;
		return (tab);
	}
	range = max - min;
	if (!(tab = (int *)malloc(sizeof(int) * range)))
		return (0);
	i = -1;
	while (++i < range)
	{
		tab[i] = min;
		min++;
	}
	return (tab);
}
