# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luca <luca@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 13:25:39 by lpicciri          #+#    #+#              #
#    Updated: 2026/07/25 22:57:37 by luca             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
ft_hex_utilities.c \
ft_num_utilities.c \
ft_ptr_utilities.c \
ft_bases_utilities.c \

OBJS = ${SRC:.c=.o}

RM = rm -f

CC = gcc

FLAGS = -Wall -Wextra -Werror

%.o: %.c
	${CC} ${FLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} $(OBJS)

fclean: clean
	rm -rf test
	${RM} ${NAME}

test: all
	gcc ${FLAGS} main.c libftprintf.a -o test

re: fclean all
