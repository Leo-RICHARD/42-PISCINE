/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 12:29:10 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/16 22:22:40 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printn(unsigned char *str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (*str > 31 && *str < 127)
			write(1, str, 1);
		else
			write(1, ".", 1);
		i++;
		str++;
	}
	write(1, "\n", 1);
}

void	ft_conv(unsigned long long int n, int v)
{
	int						i;
	unsigned char			c;
	unsigned long long int	nb;

	if (v == 16)
	{
		i = 1;
		nb = n;
		while (nb >= 16)
		{
			nb /= 16;
			i++;
		}
		i = 16 - i;
		while (i-- > 0)
			write(1, "0", 1);
	}
	c = n % 16;
	if (n >= 16)
		ft_conv(n / 16, 7);
	c = (c < 10) ? c + 48 : c + 87;
	write(1, &c, 1);
	if (v != 7 && v != 42)
		write(1, ": ", 2);
}

void	ft_add_spaces(int i, int size)
{
	int n;
	int nb;
	int i3;

	n = 40;
	i3 = -1;
	nb = i * 2;
	while (++i3 < i)
		if (i3 % 2)
			nb++;
	if (size % 2)
		nb++;
	while (nb < n)
	{
		write(1, " ", 1);
		nb++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)addr;
	while (i < size)
	{
		if (i % 16 == 0)
			ft_conv((unsigned long long int)(str + i), 16);
		if ((unsigned long long int)*(str + i) < 16)
			write(1, "0", 1);
		ft_conv((unsigned long long int)*(str + i), 42);
		if (i % 2 || (i + 1 == size))
			write(1, " ", 1);
		if ((i + 1) % 16 == 0)
			ft_printn(&str[i - 15], 16);
		else if ((i + 1) == size)
		{
			ft_add_spaces((i + 1) % 16, size);
			ft_printn(&str[i - (i % 16)], (i + 1) % 16);
		}
		i++;
	}
	return (addr);
}
