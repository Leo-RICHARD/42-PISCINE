/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkomadin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 12:47:20 by mkomadin          #+#    #+#             */
/*   Updated: 2020/09/13 23:14:17 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_line(char a, char b, char c, int x)
{
	int i;

	i = -1;
	ft_putchar(a);
	if (x > 2)
		while (++i < x - 2)
			ft_putchar(b);
	if (x > 1)
		ft_putchar(c);
	write(1, "\n", 1);
}

void	rush(int x, int y)
{
	int i;

	i = y;
	if (!(x > 0 && y > 0))
	{
		if (x < 0 || y < 0)
			write(1, "\nERROR: bad parameters\n", 23);
		return ;
	}
	ft_print_line('A', 'B', 'C', x);
	while (--i - 1 > 0)
		ft_print_line('B', ' ', 'B', x);
	if (y > 1)
		ft_print_line('A', 'B', 'C', x);
}
