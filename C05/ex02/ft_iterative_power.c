/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 18:17:42 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/14 19:27:51 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int res;
	int neg;

	res = nb;
	neg = 0;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power-- > 1)
		res *= nb;
	return (res);
}
