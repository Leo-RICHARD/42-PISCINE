/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 09:26:55 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/16 14:49:58 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int i3;

	i = -1;
	i3 = -1;
	while (src[++i3])
		;
	while (size != 0 && src[++i] && i < size - 1)
		dest[i] = src[i];
	if (size != 0)
		dest[i] = '\0';
	return (i3);
}
