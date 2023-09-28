/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 22:11:01 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/17 17:06:58 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

int		ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

int		main(int ac, char **av)
{
	int		i;
	int		i3;
	char	*tmp;

	i = 0;
	while (++i < ac)
	{
		i3 = 0;
		while (++i3 < ac - 1)
		{
			if (ft_strcmp(av[i3], av[i3 + 1]) > 0)
			{
				tmp = av[i3];
				av[i3] = av[i3 + 1];
				av[i3 + 1] = tmp;
			}
		}
	}
	i = 0;
	while (++i < ac)
		ft_print(av[i]);
	return (0);
}
