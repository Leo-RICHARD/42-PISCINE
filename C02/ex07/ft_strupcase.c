/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupacse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 21:35:48 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/16 22:22:18 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] > 96 && str[i] < 123)
			str[i] -= 32;
	return (str);
}
