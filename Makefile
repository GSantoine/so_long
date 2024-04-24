# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agras <agras@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 14:37:53 by agras             #+#    #+#              #
#    Updated: 2024/04/08 11:09:11 by agras            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long_bis
INCLUDES	= -I includes/

LIBDIR		= ./libft/
SRCDIR		= src/
MINILIBXDIR	= ./minilibx/

CC			= gcc

CFLAGS 		= -Wall -Wextra -Werror
RM			  = rm -f
MINILIBX  = minilibx/libmlx.a

SRCS	= 	${SRCDIR}main.c\
			${SRCDIR}read_map.c\
			${SRCDIR}input.c\
			${SRCDIR}init.c\
			${SRCDIR}move.c\
			${SRCDIR}init_textures.c\
			${SRCDIR}draw.c\
			${SRCDIR}time.c\
			${SRCDIR}exit.c\
			${SRCDIR}textures.c

OBJS	=		${SRCS:.c=.o}


%.o:	%.c includes/so_long.h
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

all:		${NAME}

${NAME}:	libs ${OBJS}
	# make --no-print-directory -sC ${LIBDIR}
	${CC} ${CFLAGS} ${OBJS} -o $@ ${INCLUDES} ${LIBDIR}libft.a ${MINILIBXDIR}libmlx_Linux.a -lXext -lX11

clean:
	# make clean --no-print-directory -C ${LIBDIR}
	make --no-print-directory -C ${LIBDIR} clean
	make --no-print-directory -C ${MINILIBXDIR} clean
	${RM} ${OBJS}


fclean:		clean cleanlibs
	${RM} ${NAME}

re:             fclean all

libs: libft.a libmlx_Linux.a

libft.a:
	make --no-print-directory -C ${LIBDIR}

libmlx_Linux.a:
	make --no-print-directory -C ${MINILIBXDIR}

libftclean:
	make fclean --no-print-directory -C ${LIBDIR}

minilibxclean:
	make clean --no-print-directory -C ${MINILIBXDIR}

cleanlibs: libftclean minilibxclean

.PHONY:         all clean fclean re libs libft.a libmlx_Linux.a libftclean minilibxclean cleanlibs
