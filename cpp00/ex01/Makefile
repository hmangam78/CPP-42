# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/26 10:30:00 by hgamiz-g          #+#    #+#              #
#    Updated: 2025/09/26 10:20:33 by hgamiz-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable name
NAME = phonebook

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

# Source files
SRCS = main.cpp \
       Contact.cpp \
       PhoneBook.cpp \
       aux.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files
HEADERS = Contact.hpp \
          PhoneBook.hpp \
          aux.hpp

# Colors for output
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

# Default target
all: $(NAME)

# Link object files to create executable
$(NAME): $(OBJS)
	@echo "$(GREEN)Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created successfully!$(RESET)"

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	@echo "$(GREEN)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files
clean:
	@echo "$(RED)Removing object files...$(RESET)"
	@rm -f $(OBJS)

# Clean everything
fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re