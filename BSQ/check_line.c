/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:28:27 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/30 18:11:25 by ereynaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int		ft_check_line_h(t_map *s_map, int x, int y, int side)
{
	int		i;
	char	**map;

	i = 0;
	map = s_map->grid;
	while (i < side)
	{
		if (map[y][x] == '.')
			x += 1;
		else
			return (0);
		i += 1;
	}
	return (1);
}

int		ft_check_last_line_h(t_map *s_map, int x, int y, int side)
{
	int		i;
	char	**map;

	i = 0;
	map = s_map->grid;
	y += side - 1;
	while (i < side)
	{
		if (map[y][x] == '.')
			x += 1;
		else
			return (0);
		i += 1;
	}
	return (1);
}

int		ft_check_line_v(t_map *s_map, int x, int y, int side)
{
	int		i;
	char	**map;

	i = 0;
	map = s_map->grid;
	while (i < side)
	{
		if (map[y][x] == '.')
			y += 1;
		else
			return (0);
		i += 1;
	}
	return (1);
}

int		ft_check_last_line_v(t_map *s_map, int x, int y, int side)
{
	int		i;
	char	**map;

	i = 0;
	map = s_map->grid;
	x += side - 1;
	while (i < side)
	{
		if (map[y][x] == '.')
			y += 1;
		else
			return (0);
		i += 1;
	}
	return (1);
}
