/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 20:20:57 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/30 16:31:11 by ereynaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_count(char *str)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (str[i])
	{
		while (str[i] && str[i] == '\n')
			i++;
		if (str[i] && str[i] != '\n')
			n++;
		while (str[i] && str[i] != '\n')
			i++;
		i++;
	}
	return (n);
}

char	*ft_alloc(char *str, int *i)
{
	int		j;
	char	*s;

	j = 0;
	s = 0;
	while (str[j] && str[j] != '\n')
		j++;
	if (!(s = (char *)malloc(sizeof(char) * (j + 2))))
		exit(0);
	j = 0;
	while (str[j] && str[j] != '\n')
	{
		s[j] = str[j];
		(*i)++;
		j++;
	}
	s[j] = '\n';
	s[j + 1] = 0;
	return (s);
}

char	**ft_split(char *str)
{
	int		i;
	int		n;
	char	**s;

	n = ft_count(str);
	if (!(s = (char **)malloc(sizeof(char *) * (n + 1))))
		exit(0);
	n = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			i++;
		if (str[i])
		{
			if (!(s[n] = ft_alloc(str + i, &i)))
				exit(0);
			n++;
		}
	}
	s[n] = 0;
	return (s);
}
