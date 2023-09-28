/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 15:23:10 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/09 18:57:40 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int i3;
	int tmp;

	i3 = 0;
	while (i3++ < size)
	{
		i = -1;
		while (++i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i + 1];
				tab[i + 1] = tab[i];
				tab[i] = tmp;
			}
		}
	}
}
