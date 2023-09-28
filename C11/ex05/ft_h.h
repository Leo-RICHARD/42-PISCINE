/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:03:37 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/28 16:42:54 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H_H
# define FT_H_H

# include <unistd.h>

void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
int		ft_plus(int a, int b, int *op);
int		ft_minus(int a, int b, int *op);
int		ft_times(int a, int b, int *op);
int		ft_divided(int a, int b, int *op);
int		ft_modulo(int a, int b, int *op);
void	ft_doop(int a, int(*f)(int a, int b, int *op), int b);

#endif
