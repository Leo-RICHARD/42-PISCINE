SRCS		= main.c strstr.c str_usual_z.c rushft.c strcpy_z.c strtrimm.c wordfinder.c strstr.c

OBJS		= ${SRCS:.c=.o}

NAME		= rush-02

CC			= cc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ft_h.h

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
