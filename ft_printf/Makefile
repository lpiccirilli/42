NAME = ./libftprintf.a

SRC = ./ft_printf.c \
./funcion.c \
./more_funcion.c \

OBJS = $(SRC:.c=.o)

HDRS = ./ft_printf.h

RM = rm -f

CC = gcc -Wall -Wextra -Werror

.c.o = ${CC} -I ${HDRS} includes -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

clean:
	${RM} $(OBJS)

fclean: clean
	${RM} $(NAME) ${OBJS}

re: $(NAME)

.PHONY: all clean fclean re
