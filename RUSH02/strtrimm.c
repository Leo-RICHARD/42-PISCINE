/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrimm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:59:56 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/27 19:41:49 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int		ft_wordlen(char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    return (i);
}

int		ft_next_word(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != ' ' && str[i] > 13)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrimm(char *str)
{
	char	*s;
	int		i;
	int		j;

	i = ft_wordlen(str);
	s = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	j = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	while (str[i] && ft_next_word(str + i))
	{
		s[j] = str[i];
		i++;
		j++;
	}
	s[j] = 0;
	return (s);
}
