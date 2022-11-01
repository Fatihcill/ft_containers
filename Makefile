# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 11:41:37 by fcil              #+#    #+#              #
#    Updated: 2022/11/01 13:39:58 by fcil             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_container
CC = c++ -g -std=c++98
FLAGS = -Wall -Wextra -Werror 

SRC_DIR	 = ./src
SRC	:= $(shell find $(SRC_DIR) -type f -name "*.cpp")
OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o  $(NAME) $(OBJ)

%.o	: %.cpp
	$(CC) $(FLAGS) -I./include/ -o $@ -c $< 

all: $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
