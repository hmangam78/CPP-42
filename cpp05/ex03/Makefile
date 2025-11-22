# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgamiz-g <hgamiz-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/08 12:40:16 by hgamiz-g          #+#    #+#              #
#    Updated: 2025/11/04 16:43:28 by hgamiz-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureacracy
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -DSHOWALL=0
INCLUDES = -I includes

SRCDIR = SRCS
OBJDIR = .objs

# Source files
SRCS = $(SRCDIR)/AForm.cpp \
	$(SRCDIR)/Bureaucrat.cpp \
	$(SRCDIR)/Intern.cpp \
	$(SRCDIR)/PresidentialPardonForm.cpp \
	$(SRCDIR)/RobotomyRequestForm.cpp \
	$(SRCDIR)/ShrubberyCreationForm.cpp \
	$(SRCDIR)/main.cpp

# Object files
OBJS = $(OBJDIR)/AForm.o \
	$(OBJDIR)/Bureaucrat.o \
	$(OBJDIR)/Intern.o \
	$(OBJDIR)/PresidentialPardonForm.o \
	$(OBJDIR)/RobotomyRequestForm.o \
	$(OBJDIR)/ShrubberyCreationForm.o \
	$(OBJDIR)/main.o

ICON_COMPILE = 🔧
ICON_LINK = 🔗
ICON_OK = ✅
ICON_FAIL = ❌
ICON_DONE = 🎉

.PHONY: all clean fclean re run

all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(ICON_LINK) Linking %s\n" $(NAME)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@if [ $$? -eq 0 ]; then printf "$(ICON_DONE) Built %s\n" $(NAME); else printf "$(ICON_FAIL) Link failed\n"; fi

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	@printf "$(ICON_COMPILE) Compiling %-30s" $<
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@ && printf " %b\n" "$(ICON_OK)" || (printf " %b\n" "$(ICON_FAIL)"; exit 1)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@printf "🧹 Cleaning objects...\n"
	@rm -rf $(OBJDIR)

fclean: clean
	@printf "🗑️  Removing binary...\n"
	@rm -f $(NAME)

re: fclean all

run: all
	@printf "▶ Running %s\n" $(NAME)
	@./$(NAME)
