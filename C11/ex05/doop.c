/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:52:37 by lrichard          #+#    #+#             */
/*   Updated: 2020/10/01 10:40:31 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	ft_doop(int a, int (*ft)(int a, int b, int *err), int b)
{
	int error;
	int	result;

	error = 0;
	result = ft(a, b, &error);
	if (error == 0)
		ft_putnbr(result);
	write(1, "\n", 1);
	return ;
}
