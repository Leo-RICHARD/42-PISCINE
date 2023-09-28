/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:02:41 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/25 15:14:14 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_stlen(char *str);

int		ft_err(char *base, int blen)
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

int		ft_digits(int nb, char *base_to)
{
	unsigned int	len;
	unsigned int	nbr;
	int				digits;

	digits = (nb < 0) ? 2 : 1;
	nbr = (nb < 0) ? (unsigned int)nb * -1 : (unsigned int)nb;
	len = (unsigned int)ft_stlen(base_to);
	while (nbr / len > 0)
	{
		digits++;
		nbr /= len;
	}
	return (digits);
}

void	ft_conv_base(unsigned int nbr, char *base, int i, char *str)
{
	unsigned int c;
	unsigned int l;

	l = ft_stlen(base);
	c = nbr % l;
	if (nbr >= l)
		ft_conv_base(nbr / l, base, i - 1, str);
	str[i] = base[c];
}

char	*ft_gnieeeee(int nb, char *base)
{
	unsigned int	nbr;
	char			*str;
	int				digits;

	digits = ft_digits(nb, base);
	if (!(str = (char *)malloc(sizeof(char) * digits + 1)))
		return (0);
	str[digits] = 0;
	if (nb < 0)
	{
		str[0] = '-';
		nbr = -nb;
	}
	else
		nbr = nb;
	ft_conv_base(nbr, base, digits - 1, str);
	return (str);
}
