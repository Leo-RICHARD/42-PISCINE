/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:10:06 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/24 15:58:23 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_slen(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int i3;

	i = 0;
	i3 = 0;
	while (dest[i3])
		i3++;
	while (src[i])
	{
		dest[i3 + i] = src[i];
		i++;
	}
	dest[i3 + i] = '\0';
	return (dest);
}

void	ft_append(char **strs, char *s, int size, char *sep)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_strcat(s, strs[i]);
		if (i + 1 != size)
			ft_strcat(s, sep);
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		l;
	char	*s;

	i = 0;
	l = 0;
	s = NULL;
	if (size < 1)
	{
		if (!(s = (char *)malloc(sizeof(char))))
			return (0);
		return (s);
	}
	while (i < size)
	{
		l += ft_slen(strs[i]);
		i++;
	}
	l += (ft_slen(sep) * (size - 1));
	if (!(s = (char *)malloc(sizeof(char) * (l + 1))))
		return (0);
	s[0] = '\0';
	ft_append(strs, s, size, sep);
	return (s);
}
