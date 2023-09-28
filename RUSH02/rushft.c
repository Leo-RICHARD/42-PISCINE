/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rushft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:19:36 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/27 23:38:36 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	ft_print_words(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putstr(s[i]);
		if (s[i + 1])
			write(1, " ", 1);
		else
			write(1, "\n", 1);
		i++;
	}
}

char	**ft_revtab(char **s)
{
	int		i;
	int		l;
	char	*stmp;

	l = 0;
	while (s[l] != 0)
		l++;
	l--;
	i = 0;
	while (i < l)
	{
		stmp = s[i];
		s[i] = s[l];
		s[l] = stmp;
		i++;
		l--;
	}
	return (s);
}

char	**ft_store_words(char *nbr, char *buf)
{
	int		i;
	int		j;
	int		slen;
	char	**s;

	s = 0;
	slen = ft_strlen(nbr);
	if (!(s = (char **)malloc(sizeof(char *) * (slen * 20))))
		return (0);
	nbr = ft_strrev(nbr);
	i = 0;
	j = 0;
	while (nbr[i])
	{
		if (!(s[j] = (char *)malloc(sizeof(char) * 10000)))
			return (0);
		s[j][0] = 1;
		if (!(i % 3 == 1 && nbr[i] == '1'))
		{
			s[j] = ft_find_word(i, nbr, buf);
			j++;
		}
		i++;
	}
	s[slen] = 0;
	return (s);
}

void	ft_rush(char *nb, char *buf)
{
	int		i;
	int		j;
	char	**s;
	char	*nbr;

	i = ft_strlen(nb);
	nbr = (char *)malloc(sizeof(char) * (i + 1));
	if (i != 1)
	{
		i = 0;
		while (nb[i] == '0')
			i++;
		j = 0;
		while (nb[i])
		{
			nbr[j] = nb[i];
			i++;
			j++;
		}
		nbr[j] = 0;
		s = ft_store_words(nbr, buf);
	}
	else
		s = ft_store_words(nb, buf);
	s = ft_revtab(s);
	ft_print_words(s);
	free(s);
	free(buf);
}
