/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 14:05:59 by lrichard          #+#    #+#             */
/*   Updated: 2020/10/01 22:00:22 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int	res;
	int	sort_type;

	i = -1;
	sort_type = 0;
	if (tab == 0 || !tab[0])
		return (1);
	while (++i < length - 1)
	{
		res = f(tab[i], tab[i + 1]);
		if (sort_type == 0 && res)
			sort_type = (res < 0) ? 1 : -1;
		if (res)
			if ((sort_type == 1 && res > 0) || (sort_type == -1 && res < 0))
				return (0);
	}
	return (1);
}
