/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcnts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:55:20 by lrichard          #+#    #+#             */
/*   Updated: 2020/10/01 10:40:21 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int		ft_plus(int a, int b, int *error)
{
	*error = 0;
	return (a + b);
}

int		ft_minus(int a, int b, int *error)
{
	*error = 0;
	return (a - b);
}

int		ft_times(int a, int b, int *error)
{
	*error = 0;
	return (a * b);
}

int		ft_divided(int a, int b, int *error)
{
	if (b == 0)
	{
		ft_putstr("Stop : division by zero");
		*error = 1;
		return (0);
	}
	return (a / b);
}

int		ft_modulo(int a, int b, int *error)
{
	if (b == 0)
	{
		ft_putstr("Stop : modulo by zero");
		*error = 1;
		return (0);
	}
	return (a % b);
}
