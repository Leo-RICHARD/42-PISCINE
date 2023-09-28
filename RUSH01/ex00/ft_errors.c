/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 10:38:08 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/20 22:15:17 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_new_str(char *str);
int		ft_strlen(char *str);

int		ft_free(char *newstr, int ret)
{
	free(newstr);
	return (ret);
}

int		ft_errors(char *str)
{
	int		i;
	int		j;
	char	*newstr;

	if (!(newstr = ft_new_str(str)))
		return (ft_free(newstr, 0));
	i = ft_strlen(newstr);
	if ((i / 4) < 3 || (i / 4) > 9)
		return (ft_free(newstr, 0));
	j = 0;
	while (newstr[j] != '\0')
	{
		if (!((newstr[j] >= 49 && newstr[j] <= ((i / 4) + 48))))
			return (ft_free(newstr, 0));
		j++;
	}
	return (ft_free(newstr, 1));
}
