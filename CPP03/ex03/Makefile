# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/09 00:11:41 by magrabko          #+#    #+#              #
#    Updated: 2025/04/09 00:13:05 by magrabko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=			diamondtrap

CXX=			c++

CXXFLAGS= 		-Wall -Wextra -Werror -g3 -std=c++98

CYAN= 			\033[1;36m
GREEN_B=		\033[1;32m
RESET= 			\033[0m

OBJ_PATH= 		obj

SRC=			main.cpp		\
				ClapTrap.cpp	\
				ScavTrap.cpp	\
				FragTrap.cpp	\
				DiamondTrap.cpp	\
				
OBJ= 			$(addprefix $(OBJ_PATH)/, $(notdir $(SRC:.cpp=.o)))

all: $(NAME)

$(OBJ_PATH)/%.o: %.cpp | $(OBJ_PATH)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(NAME): $(OBJ)
	@$(CXX) $(OBJ) -o $(NAME)
	@printf "\n${CYAN}"
	@printf "   ░█▀▀░█░█░█▀█░▀▀█\n"
	@printf "   ░█▀▀░▄▀▄░█░█░░▀▄\n"
	@printf "   ░▀▀▀░▀░▀░▀▀▀░▀▀▀\n"
	@printf "\n\n${RESET}"
	@printf "   \033[1musage: ./diamondtrap\033[0m"
	@printf "\n\n"

clean:
	@rm -rf $(OBJ_PATH)
	@printf "\n\n${GREEN_B}"
	@printf "   ░█▀▀░█░░░█▀▀░█▀█░█▀█░█░█░█▀█░░█\n"
	@printf "   ░█░░░█░░░█▀▀░█▀█░█░█░█░█░█▀▀░░▀\n"
	@printf "   ░▀▀▀░▀▀▀░▀▀▀░▀░▀░▀░▀░▀▀▀░▀░░░░▀\n"
	@printf "\n\n${RESET}"

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
