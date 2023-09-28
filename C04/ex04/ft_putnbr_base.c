/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 15:48:51 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/17 15:14:07 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_len(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

int		ft_baserror(char *base, int blen)
{
	int i;
	int i3;

	i = -1;
	if (blen < 2)
		return (1);
	while (++i < blen)
	{
		i3 = -1;
		while (base[++i3] && i3 < blen)
		{
			if (i3 != i && base[i3] == base[i])
				return (1);
			if (base[i3] == 45 || base[i3] == 43)
				return (1);
		}
	}
	return (0);
}

void	ft_rec(int long nbr, char *base, int long blen)
{
	int	long	i;

	i = nbr % blen;
	if (nbr >= blen)
		ft_rec(nbr / blen, base, blen);
	write(1, &base[i], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				baselength;
	long int		n;

	baselength = ft_len(base);
	if (ft_baserror(base, baselength))
		return ;
	n = nbr;
	if (nbr < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	ft_rec(n, base, baselength);
}
