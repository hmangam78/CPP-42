# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgamiz-g <hgamiz-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/03 19:00:00 by hgamiz-g          #+#    #+#              #
#    Updated: 2025/10/06 09:20:49 by hgamiz-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animals

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCDIR = .
OBJDIR = obj

SOURCES = animals.cpp \
		  Animal.cpp \
		  Dog.cpp \
		  Cat.cpp \
		  WrongAnimal.cpp \
		  WrongCat.cpp

OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)

# Colors and icons
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[1;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m

# Progress counter
COMPILED = 0
TOTAL = $(words $(SOURCES))

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(CYAN)🔗 Linking executable...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) compiled successfully!$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	@$(eval COMPILED=$(shell echo $$(($(COMPILED)+1))))
	@echo "$(YELLOW)⚙️  Compiling [$(COMPILED)/$(TOTAL)]...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(RED)🧹 Cleaning object files...$(RESET)"
	@rm -rf $(OBJDIR)
	@echo "$(GREEN)✨ Object files cleaned!$(RESET)"

fclean: clean
	@echo "$(RED)🗑️  Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)✨ All clean!$(RESET)"

re: fclean all

.PHONY: all clean fclean re