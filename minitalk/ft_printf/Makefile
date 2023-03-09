# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 13:25:39 by lpicciri          #+#    #+#              #
#    Updated: 2023/02/20 19:42:07 by lpicciri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
ft_funcion.c \
ft_more_funcion.c

OBJS = ${SRC:.c=.o}

RM = rm -f

CC = gcc

FLAGS = -Wall -Wextra -Werror

%.c.o:
	${CC} ${FLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} $(OBJS)

fclean: clean
	${RM} ${NAME}

re: fclean all
