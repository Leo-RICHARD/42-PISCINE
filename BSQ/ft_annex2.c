/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annex2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 10:42:41 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/30 23:05:48 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	ft_lol(t_map *s_map, int end, int *solved)
{
	int x;
	int	y;

	x = 0;
	y = (end) ? s_map->height - 1 : 0;
	s_map->bs_side = 1;
	while (x < s_map->width && s_map->grid[y][x] != '.')
		x++;
	s_map->bs_x = x;
	if (s_map->grid[y][x] == '.')
		*solved = 1;
	else
		s_map->grid[y][x] = 0;
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int i3;

	i = -1;
	i3 = -1;
	while (dest[++i3])
		;
	while (src[++i])
		dest[i3 + i] = src[i];
	dest[i3 + i] = '\0';
	return (dest);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int		i;

	i = 0;
	while (src[i] && n > i)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
