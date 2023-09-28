/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:58:07 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/25 15:13:43 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = -1;
	if (!(dest = (char *)malloc(sizeof(dest) * (ft_strlen(src) + 1))))
		return (NULL);
	while (src[++i])
		dest[i] = src[i];
	dest[i] = 0;
	return (dest);
}
