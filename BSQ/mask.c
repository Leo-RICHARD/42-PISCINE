/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 21:57:29 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/30 00:15:03 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	**ft_apply_mask(char **map, char *charset)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == charset[0])
				map[i][j] = '.';
			j += 1;
		}
		i += 1;
	}
	return (map);
}

char	**ft_reverse_mask(char **map, char *charset)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '.')
				map[i][j] = charset[0];
			j += 1;
		}
		i += 1;
	}
	return (map);
}
