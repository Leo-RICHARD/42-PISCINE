/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:27:20 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/25 11:27:29 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_err(char *base, int blen);
char	*ft_gnieeeee(int n, char *base);

int		ft_stlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_er(char *base, int blen)
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			i;
	long int	nb;
	int			pos;

	i = 0;
	nb = 0;
	pos = 1;
	if (ft_er(base_from, ft_stlen(base_from))
				|| ft_err(base_to, ft_stlen(base_to)))
		return (0);
	while (nbr[i] == 32 || (nbr[i] > 8 && nbr[i] < 14))
		i++;
	while (nbr[i] == 43 || nbr[i] == 45)
		if (nbr[i++] == 45)
			pos *= -1;
	while (ft_base_index(nbr[i], base_from) != -1)
	{
		nb *= ft_stlen(base_from);
		nb += ft_base_index(nbr[i], base_from);
		i++;
	}
	return (ft_gnieeeee(nb * pos, base_to));
}
