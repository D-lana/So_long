# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlana <dlana@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 19:48:30 by dlana             #+#    #+#              #
#    Updated: 2021/11/19 21:02:17 by dlana            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	gcc
RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	ft_split.c ft_itoa.c ft_strdup.c ft_strlen.c \

OBJS		=	${SRCS:.c=.o}

%.o: %.c	Makefile libft.h
			${CC} ${CFLAGS} -c $< -o $@ 

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

all:		${NAME}
	
clean:	
			${RM} ${OBJS}
			
fclean:		clean
			${RM} ${NAME} 

re:			fclean all

.PHONY: all clean fclean re