/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 18:09:00 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/30 23:39:32 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int		ft_file_len(char *path)
{
	int		r;
	int		n;
	int		fd;
	char	*buf;

	n = 0;
	if (!(buf = (char *)malloc(sizeof(char) * 3102)))
		exit(0);
	fd = open(path, O_RDONLY);
	if (fd != -1)
	{
		r = 1;
		while (r)
		{
			r = read(fd, buf, 3101);
			if (r == -1)
				exit(0);
			n += r;
		}
		close(fd);
	}
	free(buf);
	return (n);
}

char	*ft_realloc(char *src)
{
	int		i;
	int		j;
	int		len;
	char	*buf;

	i = 0;
	j = 0;
	len = ft_strlen(src);
	if (!(buf = (char *)malloc(sizeof(char) * (len + 3102))))
		exit(0);
	while (src[i])
	{
		buf[i] = src[i];
		i += 1;
		j += 1;
	}
	buf[i] = 0;
	free(src);
	return (buf);
}

char	*ft_read_input(char *map)
{
	int		r;
	char	buf[3102];

	r = 1;
	if (!(map = (char *)malloc(sizeof(char) * 3102)))
		exit(0);
	while (r)
	{
		r = read(0, buf, 3101);
		buf[r] = 0;
		map = ft_strcat(map, buf);
		if (ft_strlen(map) == 3101)
			map = ft_realloc(map);
	}
	return (map);
}

char	*ft_read_file(char *map, char *path)
{
	int		r;
	int		file_len;
	int		fd;

	file_len = ft_file_len(path);
	if (!(map = (char *)malloc(sizeof(char) * (file_len + 1))))
		exit (0);
	fd = open(path, O_RDONLY);
	if (fd != -1)
	{
		r = read(fd, map, file_len);
		if (r == -1)
			exit(0);
		close(fd);
	}
	else
	{
		write(2, "map error\n", 10);
		return (0);
	}
	map[file_len] = 0;
	return (map);
}

int		main(int ac, char **av)
{
	int		i;
	char	*map;
	char	charset[4];
	t_map	s_map;

	map = 0;
	if (ac == 1)
		map = ft_read_input(map);
	else
	{
		i = 1;
		while (av[i])
		{
			map = ft_read_file(map, av[i]);
			if (map == NULL
					|| !ft_parse(map, charset, &(s_map.width), &(s_map.height)))
				return (0);
			s_map.grid = ft_split(map + ft_line_len(map) + 1);
			ft_solve(&s_map, charset);
			if (ac > 2)
				write(1, "\n", 1);
			i++;
			free(map);
		}
	}
	return (0);
}
