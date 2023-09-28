/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 12:18:58 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/20 22:14:05 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_split_args(char *str, int size)
{
	int		i;
	int		j[2];
	char	**s;

	j[0] = -1;
	i = -1;
	if (!(s = (char **)malloc(sizeof(char *) * 5)))
		exit(0);
	s[5] = 0;
	while (++i < 5)
	{
		if (!(s[i] = (char *)malloc(sizeof(char) * (size + 1))))
			exit(0);
		s[i][size] = 0;
	}
	i = -1;
	while (str[++i])
	{
		if (i % size == 0 && !(j[1] = 0))
			j[0]++;
		s[j[0]][j[1]] = str[i];
		j[1]++;
	}
	return (s);
}
