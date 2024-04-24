# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agras <agras@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 01:48:03 by agras             #+#    #+#              #
#    Updated: 2024/04/06 19:10:04 by agras            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
SRCS		= 	ft_isalpha.c\
				ft_isdigit.c\
				ft_isalnum.c\
				ft_isascii.c\
				ft_isprint.c\
				ft_strlen.c\
				ft_memset.c\
				ft_bzero.c\
				ft_substr.c\
				ft_strjoin.c\
				ft_memcpy.c\
				ft_memcmp.c\
				ft_memmove.c\
				ft_strlcpy.c\
				ft_strlcat.c\
				ft_toupper.c\
				ft_tolower.c\
				ft_strchr.c\
				ft_strrchr.c\
				ft_strncmp.c\
				ft_memchr.c\
				ft_strnstr.c\
				ft_atoi.c\
				ft_calloc.c\
				ft_strdup.c\
				ft_strtrim.c\
				ft_strmapi.c\
				ft_striteri.c\
				ft_putstr_fd.c\
				ft_putnbr_fd.c\
				ft_putendl_fd.c\
				ft_putchar_fd.c\
				ft_itoa.c\
				ft_split.c\
				gnl/get_next_line.c\
				gnl/get_next_line_utils.c\
				free_2d_tab.c\
				ft_strcat_malloc.c\

BONUS		=	ft_lstsize.c\
				ft_lstnew.c\
				ft_lstmap.c\
				ft_lstlast.c\
				ft_lstiter.c\
				ft_lstdelone.c\
				ft_lstclear.c\
				ft_lstadd_front.c\
				ft_lstadd_back.c

OBJS		= ${SRCS:.c=.o}
OBJSB		= ${BONUS:.c=.o}
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		ar rcs ${NAME} ${OBJS}

bonus:		${OBJS} ${OBJSB}
		ar rcs ${NAME} ${OBJSB}

all: 		${NAME}

# so:
# 	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
# 	gcc -nostartfiles -shared -o libft.so $(OBJS)

clean:
		${RM} ${OBJS} ${OBJSB}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

