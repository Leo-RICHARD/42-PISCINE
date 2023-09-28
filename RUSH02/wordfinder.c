/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:01:15 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/27 23:34:40 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

char	*ft_gnieeeeeeeeeeeeeeeee(char *nbr)
{
	int i;

	i = -1;
	if (!(nbr = (char *)malloc(sizeof(char) * 42)))
		return (0);
	while (++i < 41)
		nbr[i] = '0';
	nbr[41] = 0;
	return (nbr);
}

char	*ft_more(int rank, char *index)
{
	char *nbr;
	char *buf;

	nbr = 0;
	nbr = ft_gnieeeeeeeeeeeeeeeee(nbr);
	buf = (char *)malloc(sizeof(char) * 1000);
	nbr[rank + 1] = 0;
	nbr[0] = '1';
	buf[0] = ' ';
	buf = ft_strcat(buf, ft_strtrimm(ft_strstr_word(index, nbr)));
	return (buf);
}

char	*ft_tens(int rank, char *c, char *index)
{
	char *nbr;
	char *buf;

	nbr = 0;
	nbr = ft_gnieeeeeee(nbr);
	buf = (char *)malloc(sizeof(char) * 64);
	nbr[2] = 0;
	nbr[1] = c[rank];
	nbr[0] = c[rank + 1];
	buf = ft_strstr_word(index, nbr);
	return (buf);
}

char	*ft_gnieeeeeee(char *nbr)
{
	int i;

	i = -1;
	if (!(nbr = (char *)malloc(sizeof(char) * 3)))
		return (0);
	while (++i < 3)
		nbr[i] = '0';
	return (nbr);
}

char	*ft_find_word(int rank, char *c, char *index)
{
	char	*str;
	char	*nbr;

	nbr = 0;
	if (!(nbr = ft_gnieeeeeee(nbr)))
		return (0);
	nbr[0] = c[rank];
	nbr[(rank != 2) ? rank % 3 + 1 : 1] = 0;
	if (!(str = (char *)malloc(sizeof(char) * 10000)))
		return (0);
	str[0] = 0;
	if (rank % 3 == 0 && c[rank + 1] == '1')
		str = ft_strtrimm(ft_tens(rank, c, index));
	else if (c[rank] != '0' || ft_strlen(c) == 1)
		str = ft_strtrimm(ft_strstr_word(index, nbr));
	if (rank % 3 == 2 && c[rank] != '0')
		str = ft_strcat(str, " hundred");
	if (rank % 3 == 0 && rank > 2 && c[rank] != 0)
		str = ft_strcat(str, ft_more(rank, index));
	return (str);
}
