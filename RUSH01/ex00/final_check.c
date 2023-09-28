/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 23:55:17 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/20 12:01:21 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_column_downward(char *str, int id_value, char **args, int size)
{
	int i;
	int nb_view;
	int height_max;
	int coln;

	coln = id_value % size;
	i = id_value;
	height_max = 0;
	nb_view = 0;
	while (i >= coln)
	{
		if (id_value != i && str[i] == str[id_value])
			return (0);
		if (height_max < str[i])
		{
			nb_view++;
			height_max = str[i];
		}
		i -= size;
	}
	if (nb_view == args[1][coln] - 48)
		return (1);
	else
		return (0);
}

int	ft_check_column_upward(char *str, int id_value, char **args, int size)
{
	int i;
	int nb_view;
	int height_max;
	int coln;

	coln = id_value % size;
	i = coln;
	height_max = 0;
	nb_view = 0;
	while (i <= id_value)
	{
		if (id_value != i && str[i] == str[id_value])
			return (0);
		if (height_max < str[i])
		{
			nb_view++;
			height_max = str[i];
		}
		i += size;
	}
	if (nb_view == args[0][coln] - 48)
		return (1);
	else
		return (0);
}

int	ft_check_row_right(char *str, int id_value, char **args, int size)
{
	int i;
	int nb_view;
	int height_max;
	int row;

	row = id_value / size;
	i = id_value;
	nb_view = 0;
	height_max = 0;
	while (i >= row * size)
	{
		if (i != id_value && str[i] == str[id_value])
			return (0);
		if (height_max < str[i])
		{
			nb_view++;
			height_max = str[i];
		}
		i--;
	}
	if (nb_view == args[3][row] - 48)
		return (1);
	else
		return (0);
}

int	ft_check_row_left(char *str, int id_value, char **args, int size)
{
	int i;
	int nb_view;
	int height_max;
	int row;

	row = id_value / size;
	i = row * size;
	nb_view = 0;
	height_max = 0;
	while (i <= id_value)
	{
		if (i != id_value && str[i] == str[id_value])
			return (0);
		if (height_max < str[i])
		{
			nb_view++;
			height_max = str[i];
		}
		i++;
	}
	if (nb_view == args[2][row] - 48)
		return (1);
	else
		return (0);
}
