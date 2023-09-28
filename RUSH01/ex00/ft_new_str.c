/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 11:27:57 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/20 14:52:12 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);

char	*ft_new_str(char *str)
{
	char	*newstr;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(str);
	if (i > 71 || i < 23)
		return (0);
	if (!(newstr = malloc(sizeof(char) * 37)))
		exit(0);
	i = 0;
	while (str[i])
	{
		if (str[i + 1] && i % 2 && str[i] == 32)
			i++;
		else if (i % 2 == 0 && str[i] != 32)
			newstr[j++] = str[i++];
		else
			return (0);
	}
	newstr[j] = '\0';
	return (newstr);
	free(newstr);
}
