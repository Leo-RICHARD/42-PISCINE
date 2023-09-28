/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ten_to_nineteen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 09:12:56 by deustach          #+#    #+#             */
/*   Updated: 2020/09/27 13:52:51 by deustach         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	skip(char c)
{
	int		i;
	char	*skip_char;

	skip_char = ":0123456789";
	i = 0;
	while (i < 13)
	{
		if (c == skip_char[i])
			return (-1);
		i++;
	}
	return (0);
}

char	*make_str(char c, char *buf, char  *str_return)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (c != '\n')
	{
		if (!skip(c))
		{
			str_return[j] = c;
			j++;
		}
		i++;
		c = buf[i];
	}
	str_return[j] = 0;
	return (str_return);
}

void	search(char *buf, char **argv)
{
	char	*str_return;
	char 	c;
	char	d;
	int		i;
	int 	j;
	
	j = 0;
	i = -1;
	c = buf[0];
	d = buf[1];
	str_return = (char *)malloc(sizeof(char) * 500);
	while (!(argv[1][0] == c && argv[1][1] == d))
	{
		i++;
		c = buf[i];
		d = buf[i + 1];
	}
	str_return = make_str(c, buf + i, str_return);
	while (str_return[j] != 0)
	{
		write(1, &(str_return[j]), 1);
		j++;
	}
}


int	main (int argc, char **argv)
{
	int number_dict;
	char buf[50000];
	int size;

	number_dict = open("Dict_English.txt", O_RDONLY);
	if (number_dict != -1)
	{
		size = read(number_dict, buf, 255);
		search(buf, argv);
		close(number_dict);
	}
	else
		write(1, "Error, opening impossible\n", 26);
	return (0);
}
