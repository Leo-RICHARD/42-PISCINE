/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 13:59:13 by lrichard          #+#    #+#             */
/*   Updated: 2020/10/01 10:08:57 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *array;

	if (!(array = (int *)malloc(sizeof(int) * length)))
		return (0);
	i = -1;
	while (++i < length)
		array[i] = tab[i];
	i = -1;
	while (++i < length)
		array[i] = f(tab[i]);
	return (array);
}
