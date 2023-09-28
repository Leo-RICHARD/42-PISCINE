/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:43:29 by lrichard          #+#    #+#             */
/*   Updated: 2020/09/27 23:11:43 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strcat(char *dest, char *src);
char	*ft_strrev(char *str);
int		skip_space(char *str);
void	ft_rush(char *nbr, char *buf);
char	*ft_strtrimm(char *str);
char	*ft_strstr(char *str, char *to_find);
int		word(char *str, char *to_find, int i, int j);
char	*ft_strstr_word(char *str, char *to_find);
char	*ft_find_word(int unit, char *c, char *buf);
int		ft_skip(char c);
char	*ft_make_str(char c, char *buf, char *str_return);
char	*ft_search(char *buf, char *argv);
char	*ft_gnieeeeeee(char *nbr);

#endif
