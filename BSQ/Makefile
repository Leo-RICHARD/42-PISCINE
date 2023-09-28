# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ereynaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/27 13:39:07 by ereynaud          #+#    #+#              #
#    Updated: 2020/09/30 19:16:45 by lrichard         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS = main.c ft_annex1.c ft_annex2.c parsing.c split.c solver.c mask.c check_line.c draw_square.c print_map.c \

NAME = bsq

FLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

.c.o:
	cc ${FLAGS} -c $< -o ${<:.c=.o} -I ft_h.h

all:	${NAME}

${NAME}:	${OBJS}
			cc ${FLAGS} -o ${NAME} ${OBJS}

clean:
			rm -rf ${OBJS}

fclean:	clean
			rm -rf ${NAME}

re :	 fclean all

.PHONY: all clean fclean re
