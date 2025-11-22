# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/27 09:40:00 by hgamiz-g          #+#    #+#              #
#    Updated: 2025/09/27 09:40:00 by hgamiz-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME		= violence
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -f

# Source files
SRCS		= main.cpp \
			  Weapon.cpp \
			  HumanA.cpp \
			  HumanB.cpp

# Object files
OBJS		= $(SRCS:.cpp=.o)

# Header files
HEADERS		= Weapon.hpp \
			  HumanA.hpp \
			  HumanB.hpp

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
