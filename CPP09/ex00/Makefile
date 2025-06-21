NAME=			btc

CXX=			c++

CXXFLAGS= 		-Wall -Wextra -Werror -g3 -std=c++98 -MMD

INCLD=  		-I ./include/

CYAN= 			\033[1;36m
YELLOW_B=		\033[1;32m
RESET= 			\033[0m

SRC_PATH= 		src/
OBJ_PATH= 		obj/

SRC=			$(SRC_PATH)main.cpp				\
				$(SRC_PATH)BitcoinExchange.cpp	\

OBJ= 			$(addprefix $(OBJ_PATH), $(notdir $(SRC:.cpp=.o)))

all: $(NAME)

-include $(OBJ:.o=.d)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp | $(OBJ_PATH)
	@$(CXX) $(CXXFLAGS) $(INCLD) -c $< -o $@

$(NAME): $(OBJ)
	@$(CXX) $(OBJ) -o $(NAME)
	@printf "\n${CYAN}"
	@printf "   ░█▀▀░█░█░█▀█░█▀█\n"
	@printf "   ░█▀▀░▄▀▄░█░█░█░█\n"
	@printf "   ░▀▀▀░▀░▀░▀▀▀░▀▀▀\n"
	@printf "\n\n${RESET}"
	@printf "   \033[1musage: ./btc input.txt\033[0m"
	@printf "\n\n"

clean:
	@rm -rf $(OBJ_PATH)
	@printf "\n\n${YELLOW_B}"
	@printf "   ░█▀▀░█░░░█▀▀░█▀█░█▀█░█░█░█▀█░░█\n"
	@printf "   ░█░░░█░░░█▀▀░█▀█░█░█░█░█░█▀▀░░▀\n"
	@printf "   ░▀▀▀░▀▀▀░▀▀▀░▀░▀░▀░▀░▀▀▀░▀░░░░▀\n"
	@printf "\n\n${RESET}"

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
