# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epham <epham@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/04 13:50:09 by anradix           #+#    #+#              #
#    Updated: 2018/12/21 16:56:51 by epham            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= fillit

FLAGS 	= -Wall -Wextra -Werror

SRCS 	= main.c 		\
 		  check.c 		\
 		  fcts.c 		\
 		  solver.c

OBJS 	= $(SRCS:.c=.o)

all: $(NAME)	

$(NAME): $(OBJS)
	@make -C libft/
	@gcc -g $(FLAGS) -o $(NAME) $(OBJS) -I libft/ -L libft/ -lft
	@echo "fillit successfully compiled"

%.o: %.c
	@gcc $(FLAGS) -I libft/ -o $@ -c $^

clean:
		@make -C libft/ clean
		@rm -f $(OBJS)
		@echo "fillit clean OK"

fclean: clean
		@make -C libft/ fclean
		@rm -f $(NAME)
		@echo "fillit fclean OK"


re: fclean all
		@echo "fillit re OK"
