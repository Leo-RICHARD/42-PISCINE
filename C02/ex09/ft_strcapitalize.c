/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 22:14:44 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/16 14:49:12 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_alphanumeric(char c)
{
	if (c < 48 || (c > 57 && c < 65) || (c > 90 && c < 97) || c > 122)
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] > 64 && str[i] < 91)
			str[i] += 32;
	i = -1;
	while (str[++i])
	{
		if ((str[i] > 96 && str[i] < 123)
				&& (i == 0 || !ft_is_alphanumeric(str[i - 1])))
		{
			str[i] -= 32;
		}
	}
	return (str);
}
