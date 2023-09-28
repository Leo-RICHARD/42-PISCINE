/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:40:42 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/17 17:03:40 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
			if (base[i3] == 32 || (base[i3] > 8 && base[i3] < 14))
				return (1);
		}
	}
	return (0);
}

int		ft_base_index(char c, char *base)
{
	int i;

	i = -1;
	while (base[++i])
		if (base[i] == c)
			return (i);
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int				i;
	int				nb;
	int				pos;
	int				blen;

	i = 0;
	nb = 0;
	pos = 1;
	blen = ft_len(base);
	if (ft_baserror(base, blen))
		return (0);
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	while (str[i] == 43 || str[i] == 45)
		if (str[i++] == 45)
			pos *= -1;
	while (ft_base_index(str[i], base) != -1)
	{
		nb *= blen;
		nb += ft_base_index(str[i], base);
		i++;
	}
	return (nb * pos);
}
