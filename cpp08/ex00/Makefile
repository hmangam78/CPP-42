# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 23:10:09 by hgamiz-g          #+#    #+#              #
#    Updated: 2025/11/24 09:28:45 by hgamiz-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := easyfind
CXX := c++
CXXFLAGS := -std=c++98 -Wall -Wextra -Werror

SRCS := main.cpp
OBJ_DIR := objs
OBJS := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRCS))

RM := rm -rf

GREEN := \033[1;32m
YELLOW := \033[1;33m
RED := \033[1;31m
NC := \033[0m
ICON_COMP := 🛠️
ICON_OK := ✅

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@printf "$(GREEN)🔗 Linking $(NAME)...$(NC)\n"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@printf "$(GREEN)$(ICON_OK) Built $(NAME)$(NC)\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@printf "$(YELLOW)$(ICON_COMP) Compiling $< -> $@$(NC)\n"
	@$(CXX) $(CXXFLAGS) -c $< -o $@ || { printf "$(RED)✖ Compilation failed for $<$(NC)\n"; exit 1; }

clean:
	@printf "$(YELLOW)🧹 Cleaning objects...$(NC)\n"
	@$(RM) $(OBJ_DIR)

fclean: clean
	@printf "$(YELLOW)🧹 Removing binary...$(NC)\n"
	@$(RM) $(NAME)

re: fclean all
