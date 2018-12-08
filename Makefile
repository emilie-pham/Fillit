# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anradix <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/04 13:50:09 by anradix           #+#    #+#              #
#    Updated: 2018/12/04 14:01:16 by anradix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRC = 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) -o $(NAME) $(OBJ)
	@echo "fillit successfully compiled"

clean:
		@rm -f $(OBJ)
		@echo "make clean OK"

fclean: clean
		@rm -f $(NAME)
		@echo "make fclean OK"


re: fclean all
		@echo "make re OK"
