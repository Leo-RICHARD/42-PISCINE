/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:51:23 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/30 16:31:13 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	ft_draw_square(t_map *s_map, char c)
{
	int		x;
	int		y;
	int		side;
	int		endx;
	int		endy;

	y = s_map->bs_y;
	side = s_map->bs_side;
	endy = y + s_map->bs_side;
	while (y < endy)
	{
		x = s_map->bs_x;
		endx = x + s_map->bs_side;
		while (x < endx)
		{
			s_map->grid[y][x] = c;
			x += 1;
		}
		y += 1;
	}
}
