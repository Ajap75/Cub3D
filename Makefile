# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 12:53:29 by anastruc          #+#    #+#              #
#    Updated: 2025/01/27 13:40:58 by anastruc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
COMPIL = gcc
FLAGS = -Wall -Werror -Wextra

PINK = \033[1;35m
BLUE = \033[1;36m
NC = \033[0m

SRCS = parser

PSRCS = $(addprefix srcs/, $(SRCS))

OBJS = $(PSRCS:srcs/%.cpp=objs/%.o);

all : $(NAME)

objs/%.o: srcs/%.cpp 
		@mkdir -p objs 
		@$(COMPIL) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJS)
		@$(COMPIL) $(FLAGS) -o $@ $(OBJS)
		@echo "$(BLUE)\n  parser \n$(NC) "


clean :
	@rm -rf objs
	@echo  "$(BLUE)\n  parser \n$(NC)"


fclean : clean
	@rm -rf $(NAME)
	@echo  "$(BLUE)\n  parser FULLY CLEANED \n$(NC)"

leak :
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./$(NAME)

re : fclean all

.PHONY : all clean fclean re bonus