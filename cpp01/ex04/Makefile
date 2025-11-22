# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/27 12:00:00 by hgamiz-g          #+#    #+#              #
#    Updated: 2025/09/27 11:33:26 by hgamiz-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME		= sedisforlosers

# Compiler and flags
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

# Source files
SRCS		= main.cpp

# Object files
OBJS		= $(SRCS:.cpp=.o)

# Colors for output
GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!$(RESET)"

%.o: %.cpp
	@echo "$(GREEN)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Removing object files...$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

# Test rule
test: $(NAME)
	@echo "$(GREEN)Running test...$(RESET)"
	@./$(NAME) test.txt "old" "new"
	@echo "$(GREEN)Test completed. Check test.txt.replace for results.$(RESET)"

.PHONY: all clean fclean re test