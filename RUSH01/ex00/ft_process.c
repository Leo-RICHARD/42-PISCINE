/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 11:27:06 by grivalan          #+#    #+#             */
/*   Updated: 2020/09/20 22:14:38 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_check_column(char *str, int coln, char **args, int size);
int		ft_check_row(char *str, int rown, char **args, int size);
void	ft_print_tab(char *str, int size);

void	ft_process(char *str, int id, int size, char **args)
{
	int value;

	value = 1;
	while (value <= size)
	{
		str[id] = value + 48;
		if (ft_check_column(str, id, args, size) &&
				ft_check_row(str, id, args, size))
		{
			if (id < size * size - 1)
				ft_process(str, id + 1, size, args);
			else
			{
				ft_print_tab(str, size);
				free(args);
				exit(0);
			}
		}
		value++;
	}
}
