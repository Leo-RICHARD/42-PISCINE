/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 18:27:20 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/30 23:32:12 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int		ft_line_len(char *map)
{
	int i;

	i = 0;
	while (map[i] && map[i] != '\n')
		i++;
	return (i);
}

int		ft_check_lines_number(char *map, int *nlines, int len)
{
	int		i;
	char	*buf;

	i = 0;
	if (!(buf = (char *)malloc(sizeof(char) * len)))
		exit(0);
	ft_strncpy(buf, map, len - 3);
	while (buf[i] > 47 && buf[i] < 58)
		i += 1;
	if (i != len - 3 || !(*nlines = ft_atoi_eco(buf)))
		return (0);
	i = -1;
	len = 0;
	while (map[++i])
		if ((map[i] < 32 || map[i] == 127) && map[i] != '\n')
			return (0);
		else if (map[i] == '\n')
			len += 1;
	if (len - 1 != *nlines)
		return (0);
	free(buf);
	return (*nlines);
}

int		ft_check_lines(char *map, char *charset, int nlines, int llen)
{
	int i;
	int	n;

	n = 0;
	i = 0;
	if (!map[0])
		return (0);
	while (n < nlines)
	{
		if (ft_line_len(map + i) != llen)
			return (0);
		i += llen + 1;
		n += 1;
	}
	i = -1;
	while (map[++i])
		if (map[i] != charset[0] && map[i] != charset[1] && map[i] != '\n')
			return (0);
	return (1);
}

char	*ft_get_charset(char *map, char *charset, int first_line_len)
{
	int		i;
	int		j;

	i = first_line_len - 3;
	if (map[i] == map[i + 1] || map[i] == map[i + 2] ||
	map[i + 1] == map[i + 2])
		return (0);
	j = 0;
	while (map[i] != '\n')
	{
		if (map[i] < 32 || map[i] == 127)
			return (0);
		charset[j] = map[i];
		i += 1;
		j += 1;
	}
	charset[3] = 0;
	return (charset);
}

int		ft_parse(char *map, char *charset, int *width, int *height)
{
	int		nlines;
	int		line_len;

	line_len = ft_line_len(map);
	if (line_len < 4 || !ft_check_lines_number(map, &nlines, line_len))
	{
		write(1, "map error\n", 10);
		return (0);
	}
	*height = nlines;
	if (!(charset = ft_get_charset(map, charset, line_len)))
	{
		write(1, "map error\n", 10);
		return (0);
	}
	map += line_len + 1;
	line_len = ft_line_len(map);
	*width = line_len;
	if (!(ft_check_lines(map, charset, nlines, line_len)))
	{
		write(1, "map error\n", 10);
		return (0);
	}
	return (1);
}
