# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/09 10:25:00 by hgamiz-g          #+#    #+#              #
#    Updated: 2025/12/11 11:19:39 by hgamiz-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ========================= COMPILATION VARIABLES ========================== #

NAME		= RPN
CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
SRCDIR		= SRCS
INCDIR		= includes
OBJDIR		= .objects

# ================================ FILES ===================================== #

SRCS		= SRCS/main.cpp SRCS/validations.cpp SRCS/MyExceptions.cpp \
			  SRCS/RPN.cpp
			 
OBJS		= $(OBJDIR)/main.o $(OBJDIR)/validations.o $(OBJDIR)/MyExceptions.o \
			  $(OBJDIR)/RPN.o
			

# ============================== COLORS ====================================== #

RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
MAGENTA		= \033[0;35m
CYAN		= \033[0;36m
WHITE		= \033[1;37m
RESET		= \033[0m

# ================================ ICONS ====================================== #

CHECK		= ✓
CROSS		= ✗
GEAR		= ⚙
ROCKET		= 🚀
BOOK		= 📚
TRASH		= 🗑
SPINNER	= ⌛

# ============================== RULES ======================================= #

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)$(SPINNER) $(GEAR)  Linking...$(RESET)"
	@$(CXX) $(CXXFLAGS) -I$(INCDIR) -o $(NAME) $(OBJS)
	@echo "$(GREEN)$(CHECK)  $(ROCKET) Compilation successful!$(RESET)"
	@echo "$(CYAN)$(BOOK)  Output: $(NAME)$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	@echo "$(MAGENTA)$(GEAR)  Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@
	@echo "$(GREEN)$(CHECK)  Object created: $@$(RESET)"

clean:
	@echo "$(YELLOW)$(TRASH)  Cleaning objects...$(RESET)"
	@rm -rf $(OBJDIR)
	@echo "$(GREEN)$(CHECK)  Clean done!$(RESET)"

fclean: clean
	@echo "$(RED)$(CROSS)  Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)$(CHECK)  Full clean done!$(RESET)"

re: fclean all

# ============================== HELP ======================================== #

help:
	@echo "$(CYAN)Available targets:$(RESET)"
	@echo "  $(GREEN)all$(RESET)    - Build the project"
	@echo "  $(YELLOW)clean$(RESET)  - Remove object files"
	@echo "  $(RED)fclean$(RESET)  - Remove all build artifacts"
	@echo "  $(MAGENTA)re$(RESET)     - Clean rebuild"
