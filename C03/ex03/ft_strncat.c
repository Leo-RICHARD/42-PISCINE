/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:26:20 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/15 16:13:13 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				i3;
	unsigned int	i;

	i = -1;
	i3 = -1;
	while (dest[++i3])
		;
	while (src[++i] && i < nb)
		dest[i3 + i] = src[i];
	dest[i3 + i] = '\0';
	return (dest);
}
