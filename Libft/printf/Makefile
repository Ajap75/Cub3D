# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 08:48:56 by anastruc          #+#    #+#              #
#    Updated: 2024/04/26 11:12:33 by anastruc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRC = ft_putchar.c ft_putstr.c ft_putnbr.c ft_print_conversion.c ft_printf.c ft_putnbr_base.c ft_putnbr_u.c ft_putnbr_base_p.c

OBJ = ${SRC:.c=.o}

RM = rm -f

all : ${NAME}

${NAME} : ${OBJ}
	ar rc $@ $^

%.o : %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
