/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 13:57:54 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/30 23:01:25 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int		ft_check_square_fits(t_map *s_map, int x, int y, int side)
{
	if (x >= s_map->width - s_map->bs_side
			|| y >= s_map->height - s_map->bs_side)
		return (0);
	if (ft_check_line_h(s_map, x, y, side)
			&& ft_check_last_line_h(s_map, x, y, side)
				&& ft_check_line_v(s_map, x, y, side)
					&& ft_check_last_line_v(s_map, x, y, side))
	{
		return (1);
	}
	return (0);
}

void	ft_try_square(t_map *s_map, int x, int y)
{
	int bs_side;
	int side_tmp;

	bs_side = s_map->bs_side + 1;
	if (ft_check_square_fits(s_map, x, y, bs_side))
	{
		side_tmp = bs_side - 1;
		while (side_tmp > 0)
		{
			if (!(ft_check_square_fits(s_map, x, y, side_tmp)))
				return ;
			side_tmp -= 1;
		}
		s_map->bs_x = x;
		s_map->bs_y = y;
		s_map->bs_side += 1;
		while (ft_check_square_fits(s_map, x, y, s_map->bs_side + 1))
			s_map->bs_side += 1;
		return ;
	}
}

void	ft_process(t_map *s_map, int x, int y, int *solved)
{
	int	width;
	int	height;

	width = s_map->width;
	height = s_map->height;
	while (y < height - s_map->bs_side)
	{
		ft_try_square(s_map, x, y);
		x += 1;
		if (!(x < width - s_map->bs_side))
		{
			x = 0;
			y += 1;
		}
		if (y == height)
			ft_lol(s_map, 1, solved);
	}
}

void	ft_solve(t_map *s_map, char *charset)
{
	int solved;

	solved = 0;
	s_map->grid = ft_apply_mask(s_map->grid, charset);
	s_map->bs_side = 0;
	s_map->bs_x = 0;
	s_map->bs_y = 0;
	if (s_map->height == 1)
		ft_lol(s_map, 0, &solved);
	else
		ft_process(s_map, 0, 0, &solved);
	s_map->grid = ft_reverse_mask(s_map->grid, charset);
	if (solved)
		ft_draw_square(s_map, charset[2]);
	ft_print_map(s_map->height, s_map->grid);
}
