/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 14:52:21 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/24 15:58:42 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int				i;
	long long int	r;

	i = -1;
	r = max - min;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	if (!(*range = (int *)malloc(sizeof(int) * r)))
		return (-1);
	while (i++ < r)
	{
		(*range)[i] = min;
		min++;
	}
	return (r);
}
