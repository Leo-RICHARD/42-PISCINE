/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 20:20:57 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/25 12:05:11 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_contains(char *charset, char c)
{
	int i;

	i = -1;
	while (charset[++i])
		if (charset[i] == c)
			return (1);
	return (0);
}

int		ft_count(char *str, char *charset)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (str[i])
	{
		while (str[i] && ft_contains(charset, str[i]))
			i++;
		if (str[i] && !ft_contains(charset, str[i]))
			n++;
		while (str[i] && !ft_contains(charset, str[i]))
			i++;
		i++;
	}
	return (n);
}

char	*ft_alloc(char *str, char *charset, int *i)
{
	int		j;
	char	*s;

	j = 0;
	s = 0;
	while (str[j] && !ft_contains(charset, str[j]))
		j++;
	if (!(s = (char *)malloc(sizeof(char) * (j + 1))))
		return (0);
	j = 0;
	while (str[j] && !ft_contains(charset, str[j]))
	{
		s[j] = str[j];
		(*i)++;
		j++;
	}
	s[j] = 0;
	return (s);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		n;
	char	**s;

	n = ft_count(str, charset);
	if (!(s = (char **)malloc(sizeof(char *) * (n + 1))))
		return (0);
	n = 0;
	i = 0;
	while (str[i])
	{
		while (ft_contains(charset, str[i]))
			i++;
		if (str[i] && !ft_contains(charset, str[i]))
		{
			if (!(s[n] = ft_alloc(str + i, charset, &i)))
				return (0);
			n++;
		}
	}
	s[n] = 0;
	return (s);
}
