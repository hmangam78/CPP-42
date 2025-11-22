# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/02 15:55:09 by hgamiz-g          #+#    #+#              #
#    Updated: 2025/09/29 11:50:45 by hgamiz-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
COMPILER = c++
FLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -rf

all: $(NAME)

SRCS = megaphone.cpp

OBJ_FILES = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(COMPILER) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES)
	$(COMPILER) $(FLAGS) $^ -o $@

clean:
	$(RM) $(OBJ_FILES)

fclean:
	$(RM) $(NAME)
	$(RM) $(OBJ_FILES)

re: clean all

run:
	./$(NAME)

.PHONY: all clean fclean re run