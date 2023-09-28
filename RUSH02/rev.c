/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:16:06 by amazari           #+#    #+#             */
/*   Updated: 2020/09/26 15:16:07 by amazari          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int         ft_strlen(char *str)
{
    int     i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}


// Pour strstr verifie que le mot entier to_find est bien dans str
// 1 si oui, 0 si non
int			mot(char *str, char *to_find, int i, int j)
{
	int len;
	int size;

	len = ft_strlen(to_find);
	size = 0;
	while (str[i] == to_find[j])
	{
		size++;
		j++;
		i++;
	}
	if (len == size || len == size - 1)
		return (1);
	else
		return (0);
}

// Comme strstr return tout le reste apres avoir touvé le nombre mais a partir du :
char		*ft_strstr_mot(char *str, char *to_find)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			if (mot(str, to_find, i, j) == 1)
            {
                while (str[i] && str[i] != ':')
                    i++;
				return (str + i + 1);
            }
		}
		i++;
	}
	return (0);
}

// Strstr classique return tout le reste apres avoir touvé le nombre
char		*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			if (mot(str, to_find, i, j) == 1)
				return (str + i);
		}
		i++;
	}
	return (0);
}


// Transforme un "five fifty" en "fifty five"
char        *ft_rev_space(char *str)
{
    int     i;
    char    *str2;
    int     j;

    i = 0;
    j = 0;
    if (ft_strstr_mot(str, " ") == 0)
        return (str);
    str2 = malloc(sizeof(char) * ft_strlen(str) + 1);
    while (str[i] && str[i] != ' ')
        i++;
    while (str[++i])
    {
        str2[j] = str[i];
        j++;
    }
    str2[j] = ' ';
    i = -1;
    while (str[++i] && str[i] != ' ')
        str2[++j] = str[i];
    str2[j + 1] = '\0';
    str = str2;
    free(str2);
    return (str);
}


// Calcule la taille de str sans les espaces pour le trimm
int         skip_space(char *str)
{
    int i;
    int j;
    int taille;

    taille = ft_strlen(str);
    j = taille;
    i = 0;
    while ((str[i] == '\t' || str[i] == '\n' || str[i] == '\f' ||\
            str[i] == '\r' || str[i] == '\v' || str[i] == ' '))
        {
            j--;
            i++;
        }
    i = taille - 1;
    while ((str[i] == '\t' || str[i] == '\n' || str[i] == '\f' ||\
            str[i] == '\r' || str[i] == '\v' || str[i] == ' '))
        {
            j--;
            i--;
        }
    return (j);
}


// Enleve les espaces avant et apres le mot
// Return str2 qui est egale a str sans les espaces
char        *ft_strtrimm(char *str)
{
    int     i;
    int     j;
    char    *str2;
    int     space;

    i = 0;
    space = skip_space(str);
    j = 0;
    str2 = malloc(sizeof(char) * space + 1);
    while ((str[i] == '\t' || str[i] == '\n' || str[i] == '\f' ||\
            str[i] == '\r' || str[i] == '\v' || str[i] == ' '))
        i++;
    while (space > 0)
    {
        str2[j] = str[i];
        i++;
        j++;
        space--;
    }
    str2[j] = '\0';
    return (str2);
}

// Compte le nombres de caracteres a copier sur la ligne apres le trimm
int    ft_mot(char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    return (i);
}

// Copie jusqu'a n caracteres src dans dest
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

// Mets nb(-1) x '0' apres le char c et le transforme en char *nbr
// Cherche la ligne nbr dans buf et gardes ce qu'il y a apres le :
// (Trimme) Efface les espaces de la ligne pour garder que le mot
// Ft_mot compte le nombre caracteres jusquau \n
// Copie le mot dans str et le return
char    *ft_find_word(int nb, char c, char *buf)
{
    char *str;
    char    *nbr;
    int     i;
    int     j;

    j = nb;
    nbr = malloc(sizeof(char) * nb + 1);
    str = malloc(sizeof(char) * 15);
    i = 1;
    nbr[0] = c;
    while (j > 1)
    {
        nbr[i] = '0';
        i++;
        j--;
    }
    nbr[i] = '\0';
    if (nb == 2 || c == '1')
    {
        buf = ft_strtrimm(ft_strstr_mot(buf, nbr));
        str = ft_strncpy(str, buf, ft_mot(buf));
    }
    else if (nb == 1)
    {
        buf = ft_strtrimm(ft_strstr_mot(buf, nbr));
        str = ft_strncpy(str, buf, ft_mot(buf));
    }
    str[ft_mot(buf)] = '\0';
    return (str);
}

// Ouverture du fichier + return du file descriptor
int     open_file()
{
    int i;
    int fd;

    i = 0;
    if (!(fd = open("numbers.dict", O_RDONLY)))
        return (-1);
    return (fd);
}

int         main()
{
    char    buf[4096];
    int     fd;

    fd = open_file();
    read(fd, buf, 4096);
    printf("%s\n", ft_find_word(3, '1', buf));
    printf("strimm =%s\n", ft_strtrimm("\t\n hey  everybody ! \t\n\v\f\r"));
    printf("str = %s\n", ft_rev_space("four fifty"));
    if (!(close(fd)))
        return (-1);
    return (0);
}