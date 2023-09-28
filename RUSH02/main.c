/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 11:20:12 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/27 22:33:02 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int		ft_file_len(char *path)
{
	int		fd;
	int		r;
	int		n;
	char	buf[13];

	n = 0;
	fd = open(path, O_RDONLY);
	if (fd != -1)
	{
		r = 1;
		while (r != 0)
		{
			r = read(fd, buf, 13);
			n += r;
		}
		close(fd);
	}
	return (n);
}

char	*ft_getlist(char *path, char *buf)
{
	int flen;
	int fd;

	flen = ft_file_len(path);
	if (flen == 0 || !(buf = (char *)malloc(sizeof(char) * flen + 1)))
	{
		if (flen)
			write(1, "Error: memory allocation failed\n", 33);
		return (0);
	}
	fd = open(path, O_RDONLY);
	if (flen && fd != -1)
	{
		read(fd, buf, flen);
		buf[flen] = 0;
		close(fd);
	}
	else
	{
		write(1, "Error: could not open file\n", 27);
		return (0);
	}
	return (buf);
}

int		main(int ac, char **av)
{
	char	*nbr;
	char	*path;
	char	*buf;

	buf = 0;
	if (ac == 1 || ac > 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (ac == 2)
	{
		nbr = av[1];
		path = "numbers.dict";
	}
	else
	{
		path = av[1];
		nbr = av[2];
	}
	if ((buf = ft_getlist(path, buf)))
		ft_rush(nbr, buf);
	return (0);
}
