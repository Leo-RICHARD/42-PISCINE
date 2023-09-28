/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 21:05:16 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/22 17:14:27 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_prime(int nb)
{
	int i;

	if (nb < 2)
		return (0);
	if (nb == 2 || nb == 3 || nb == 5 || nb == 7 || nb == 11)
		return (1);
	i = 10;
	while (++i && nb % 2 && nb % 3 && nb % 5 && nb % 7 && nb % i)
		if (i > (nb / i))
			return (1);
	return (0);
}

int		ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	while (!ft_prime(nb))
		nb++;
	return (nb);
}
