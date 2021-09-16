# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 12:36:15 by elaachac          #+#    #+#              #
#    Updated: 2021/09/16 11:37:49 by elaachac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
INCLUDE =	push_swap.h\

INC_PATH = ./includes/

vpath %.c srcs/utils

FILES =	./srcs/push_swap\
		./srcs/checkers\
		./srcs/cases\
		./srcs/utils/utils\
		./srcs/utils/utils2\
		./srcs/moves/push\
		./srcs/moves/swap\
		./srcs/moves/rotate\
		./srcs/moves/reverse\


SRCS = $(addsuffix .c, $(FILES))
OBJ = $(SRCS:.c=.o)

L_CC = clang
FLAGS = -Wall -Wextra -Werror
### COLORS ###

NOC = \033[0m
BOLD = \033[1m
UNDERLINE = \033[4m
BLACK = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
VIOLET = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m

all: 		 $(NAME)

$(NAME): 	$(OBJ)
			@echo "$(CYAN)Constructing executable:$(WHITE) $@"
			@$(L_CC) $(FLAGS) -o $(NAME) $(OBJ) $(L_LIB)
.c.o:		${SRCS}
			@echo " $(VIOLET)[$(L_CC)] $(GREEN)[$(FLAGS)]$(NOC) $(YELLOW)in progress ...:$(NOC) $< $(RED)->$(NOC) $@"
			@$(L_CC) -c -I$(INC_PATH) $< -o ${<:.c=.o}
clean:
	@echo "$(RED)Removing '.o' objects: $(NOC) $@"
	@rm -f $(OBJ)

fclean: clean
	@echo "$(RED)Removing executable: $(NOC) $@"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean

