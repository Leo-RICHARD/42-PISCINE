/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 11:52:36 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/27 17:12:16 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int i3;

	i = -1;
	i3 = -1;
	while (dest[++i3])
		;
	while (src[++i])
		dest[i3 + i] = src[i];
	dest[i3 + i] = '\0';
	return (dest);
}
