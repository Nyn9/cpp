NAME		:= diamontrap
CC			:= c++
FLAGS		:= -Wall -Wextra -Werror -std=c++98 -I./includes

SRCS_DIR	:= srcs/
SRCS_FILE	:= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
SRCS		:= $(addprefix $(SRCS_DIR), $(SRCS_FILE))

OBJS_DIR	:= objs/
OBJS		:= $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.cpp=.o)))

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	@mkdir -p $(OBJS_DIR)
	@ $(CC) $(FLAGS) -c $< -o $@

CLR_RMV		:= \033[0m
RED			:= \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN		:= \033[1;36m
RM			:= rm -f

${NAME}:	${OBJS}
			@ echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@ ${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@ echo "$(GREEN)$(NAME) is ready ![0m ✔️"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} $(OBJS_DIR)/*.o
			@ ${RM} -rf $(OBJS_DIR)
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re
