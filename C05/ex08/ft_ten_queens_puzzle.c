/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:35:15 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/22 17:15:58 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_safety_test(char *checkboard, int col)
{
	int i;

	i = col;
	while (i-- > 0)
	{
		if (checkboard[i] == checkboard[col]
				|| checkboard[i] + (col - i) == checkboard[col] ||
				checkboard[i] - (col - i) == checkboard[col])
			return (0);
	}
	return (1);
}

int		ft_trysolve(char *checkboard, int col)
{
	int i;
	int	solutions;
	int	row;

	row = 0;
	solutions = 0;
	while (row < 10)
	{
		checkboard[col] = row + 48;
		if (ft_safety_test(checkboard, col))
		{
			if (col < 9)
				solutions += ft_trysolve(checkboard, col + 1);
			else
			{
				i = -1;
				while (i++ < 9)
					write(1, &(checkboard[i]), 1);
				write(1, "\n", 1);
				solutions++;
			}
		}
		row++;
	}
	return (solutions);
}

int		ft_ten_queens_puzzle(void)
{
	int		i;
	char	checkboard[10];

	i = 0;
	while (i++ < 9)
		checkboard[i] = 0;
	return (ft_trysolve(checkboard, 0));
}
