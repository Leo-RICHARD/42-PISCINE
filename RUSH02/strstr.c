/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 19:19:07 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/27 19:32:03 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

char	*ft_strstr_word(char *str, char *to_find)
{
	int i;
	int i3;

	i = -1;
	if (!to_find[0])
		return (str);
	while (str[++i])
	{
		if (str[i] == ':')
			while (str[i] && str[i] != '\n')
				i++;
		if (str[i] == to_find[0])
		{
			i3 = 1;
			while ((to_find[i3] == str[i + i3]) && to_find[i3] != 0)
				i3++;
			if (to_find[i3] == 0)
			{
				while (str[i] && str[i] != ':')
					i++;
				return (str + i + 1);
			}
		}
	}
	return (0);
}
