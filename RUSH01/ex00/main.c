/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 12:40:33 by tbillon           #+#    #+#             */
/*   Updated: 2020/09/20 22:14:19 by grivalan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *str);
int		ft_errors(char *str);
char	*ft_new_str(char *str);
void	*ft_process(char *str, int id, int size, char **args);
char	**ft_split_args(char *str, int size);

int		main(int argc, char **argv)
{
	char	*str;
	char	*empty;
	int		size;
	char	**args;

	if (argc != 2 || ft_errors(argv[1]) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	str = ft_new_str(argv[1]);
	size = ft_strlen(str) / 4;
	if ((empty = (malloc(sizeof(char) * size * size + 1))) == NULL)
		exit(0);
	if ((args = (char**)malloc(sizeof(char*) * size + 1)) == NULL)
		exit(0);
	args = ft_split_args(str, size);
	ft_process(empty, 0, size, args);
	write(1, "Error\n", 6);
	free(str);
	free(empty);
	free(args);
	return (0);
}
