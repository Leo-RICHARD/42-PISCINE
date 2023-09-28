/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereynaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 18:12:57 by ereynaud          #+#    #+#             */
/*   Updated: 2020/09/30 22:43:27 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H_H
# define FT_H_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef	struct		s_map
{
	int		width;
	int		height;
	int		bs_side;
	int		bs_x;
	int		bs_y;
	char	**grid;
}					t_map;

int					ft_strlen(char *str);
void				ft_putstr(char *str);
int					ft_atoi_eco(char *str);
char				*ft_strcat(char *dest, char *src);
char				*ft_strdup(char *src, int buf_len);
void				ft_putnbr(int nb);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
int					ft_parse(char *map, char *charset, int *width, int *height);
int					ft_line_len(char *map);
char				**ft_split(char *map);
void				ft_solve(t_map *s_map, char *charset);
char				**ft_apply_mask(char **map, char *charset);
char				**ft_reverse_mask(char **map, char *charset);
int					ft_check_line_h(t_map *s_map, int x, int y, int side);
int					ft_check_line_v(t_map *s_map, int x, int y, int side);
int					ft_check_last_line_h(t_map *s_map, int x, int y, int side);
int					ft_check_last_line_v(t_map *s_map, int x, int y, int side);
void				ft_draw_square(t_map *s_map, char c);
void				ft_print_map(int height, char **map);
void				ft_lol(t_map *s_map, int end, int *solved);

#endif
