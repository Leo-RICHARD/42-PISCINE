/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 22:40:13 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/20 11:48:49 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_column_downward(char *str, int id_value, char **args, int size);
int	ft_check_column_upward(char *str, int id_value, char **args, int size);
int ft_check_row_right(char *str, int id_value, char **args, int size);
int ft_check_row_left(char *str, int id_value, char **args, int size);

int	ft_check_column(char *str, int id_value, char **args, int size)
{
	int i;
	int nb_view;
	int height_max;
	int coln;

	coln = id_value % size;
	i = coln;
	height_max = 0;
	nb_view = 0;
	while (i < id_value)
	{
		if (id_value != i && str[i] == str[id_value])
			return (0);
		nb_view += (height_max < str[i]) ? 1 : 0;
		height_max = (height_max < str[i]) ? str[i] : height_max;
		i += size;
	}
	if (nb_view <= args[0][coln] - 48)
		if (id_value / size + 1 == size)
			return (ft_check_column_downward(str, id_value, args, size) &&
					ft_check_column_upward(str, id_value, args, size));
		else
			return (1);
	else
		return (0);
}

int	ft_check_row(char *str, int id_value, char **args, int size)
{
	int i;
	int nb_view;
	int height_max;
	int row;

	row = id_value / size;
	i = row * size;
	nb_view = 0;
	height_max = 0;
	while (i < id_value)
	{
		if (str[i] == str[id_value])
			return (0);
		nb_view += (height_max < str[i]) ? 1 : 0;
		height_max = (height_max < str[i]) ? str[i] : height_max;
		i++;
	}
	if (nb_view <= args[2][row] - 48)
		if ((id_value + 1) % size == 0)
			return (ft_check_row_right(str, id_value, args, size) &&
					ft_check_row_left(str, id_value, args, size));
		else
			return (1);
	else
		return (0);
}
