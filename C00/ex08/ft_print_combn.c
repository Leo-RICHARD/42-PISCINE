/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:43:24 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/09 18:14:38 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_tab(char *tab, int n, int i)
{
	while (tab[++i])
		write(1, &tab[i], 1);
	if (tab[0] != '9' - n + 1)
		write(1, ", ", 2);
}

void	ft_cycle(char *tab, int n, int j)
{
	while (tab[++j])
	{
		if (tab[j] >= '9' - (n - (j + 1)))
		{
			tab[j - 1]++;
			j--;
			while (tab[++j])
				tab[j] = tab[j - 1] + 1;
		}
	}
}

void	ft_print_combn(int n)
{
	char	tab[10];
	int		i;

	i = n;
	while (i-- > 0)
		tab[i] = i + 48;
	tab[n] = '\0';
	i = n - 1;
	while (tab[0] < '9' - n + 1)
	{
		ft_print_tab(tab, n, -1);
		tab[i]++;
		if (tab[i] > '9')
			ft_cycle(tab, n, -1);
	}
	ft_print_tab(tab, n, -1);
}
