/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:01:57 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/09 18:10:00 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int a, int b)
{
	char c;

	c = a / 10 + 48;
	write(1, &c, 1);
	c = a % 10 + 48;
	write(1, &c, 1);
	write(1, " ", 1);
	c = b / 10 + 48;
	write(1, &c, 1);
	c = b % 10 + 48;
	write(1, &c, 1);
	if (!(a == 98 && b == 99))
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = -1;
	while (a++ < 98)
	{
		b = a;
		while (b++ < 99)
			ft_print(a, b);
	}
}
