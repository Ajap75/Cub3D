# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 12:53:29 by anastruc          #+#    #+#              #
#    Updated: 2025/01/28 12:16:44 by anastruc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the final executable file
NAME = cub3D_parse

# Compiler and flags
COMPIL = gcc                           # Compiler to use (GCC)
FLAGS = -Wall -Werror -Wextra          # Flags for strict compilation

# Colors for terminal output (used in echo statements)
PINK = \033[1;35m
BLUE = \033[1;36m
NC = \033[0m                          # No color (reset)

# Libft configuration
LIBFT_PATH = ./Libft/                  # Path to the Libft directory
LIBFT = $(LIBFT_PATH)libft.a           # The compiled Libft library file

# Source and object directories
SRCS_DIR = srcs# Directory containing source files
OBJS_DIR = objs# Directory where object files will be generated
HEADERS_DIR = headers# Directory containing header files

# List of source files for parsing
SRCS = main.c parsing_metadata.c

# List of header files
HEADERS =  structures.h colors.h functions.h

# Create full paths for source and object files
PSRCS = $(addprefix $(SRCS_DIR)/, $(SRCS))           # Full paths to source files
OBJS = $(PSRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)      # Converts source paths to object paths


# Default rule: Build the executable
all: $(NAME)

# Rule to build the object files
# Each source file is compiled into an object file inside the objs/ directory
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(addprefix $(HEADERS_DIR)/, $(HEADERS))
	@mkdir -p $(dir $@)                        # Ensure the object directory exists
	@$(COMPIL) $(FLAGS) -I$(HEADERS_DIR) -I$(LIBFT_PATH) -c $< -o $@
	@echo "$(PINK)Compiling: $< $(NC)"           # Print which file is being compiled

# Rule to build the executable
# Links all object files with Libft and creates the final binary
$(NAME): $(LIBFT) $(OBJS)
	@$(COMPIL) $(FLAGS) -o $@ $(OBJS) -L$(LIBFT_PATH) -lft
	@echo "$(BLUE)\n$(NAME) successfully built!$(NC)" # Success message

# Rule to build Libft
# Runs make inside the Libft directory to build libft.a
$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)
	@echo "$(PINK)Libft compiled!$(NC)"

# Rule to clean object files
# Removes the objs/ directory and its contents

debug:
	@echo "Sources: $(PSRCS)"
	@echo "Objects: $(OBJS)"
	@echo "Headers: $(HEADERS)"

clean:
	@rm -rf $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_PATH) clean              # Also clean Libft's object files
	@echo "$(BLUE)\nObject files cleaned!$(NC)"

# Rule to clean everything
# Removes the executable and the objs/ directory, and also cleans Libft
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean             # Fully clean Libft (including libft.a)
	@echo "$(BLUE)\nEverything fully cleaned!$(NC)"

# Rule to rebuild the project
# Cleans everything and builds the project from scratch
re: fclean all

# Rule to check for memory leaks using Valgrind
# Runs the executable with Valgrind to check for memory leaks
leak: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./$(NAME)

# Special target to mark these rules as "phony" (not tied to actual files)
.PHONY: all clean fclean re leak
