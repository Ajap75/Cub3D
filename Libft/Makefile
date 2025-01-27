# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 10:11:33 by anastruc          #+#    #+#              #
#    Updated: 2024/06/04 11:12:58 by anastruc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

SRC = ft_countword.c ft_free_split.c ft_atoi.c ft_strtol.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isspace.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcpy.c \
ft_strlen.c ft_strncmp.c ft_strcmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_itoa.c \
ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_striteri.c ft_strmapi.c ft_strlcat.c  \

BONUS = ft_lstnew.c ft_lstsize.c ft_lstdelone.c ft_lstlast.c ft_lstiter.c ft_lstadd_front.c ft_lstadd_back.c ft_lstclear.c ft_lstmap.c
GNL_SRC = get_next_line.c get_next_line_utils.c get_next_line_bonus.c \

PRINTF_SRC = ft_putchar.c ft_putstr.c ft_putnbr.c ft_print_conversion.c ft_printf.c ft_putnbr_base.c ft_putnbr_u.c ft_putnbr_base_p.c

OBJ = ${SRC:.c=.o}
GNL_DIR = get_next_line
GNL_OBJ = $(addprefix $(GNL_DIR)/,$(GNL_SRC:.c=.o))

PRINTF_DIR = printf
PRINTF_OBJ = $(addprefix $(PRINTF_DIR)/,$(PRINTF_SRC:.c=.o))


BONUS_OBJ = $(BONUS:.c=.o)

RM = rm -f

all : ${NAME}

${NAME} : ${OBJ} $(GNL_OBJ) $(PRINTF_OBJ)
	ar rc $@ $^

$(GNL_DIR)/%.o : $(GNL_DIR)/%.c
	@mkdir -p $(GNL_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF_DIR)/%.o : $(PRINTF_DIR)/%.c
	@mkdir -p $(PRINTF_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

%.o : %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean :
	${RM} ${OBJ} ${BONUS_OBJ}
	${RM} -r ${GNL_OBJ} ${PRINTF_OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all

bonus : ${OBJ} ${BONUS_OBJ}
	ar rc ${NAME} ${OBJ} ${BONUS_OBJ}

.PHONY : all clean fclean re bonus

