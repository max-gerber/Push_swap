# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgerber <mgerber@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/30 14:43:13 by mgerber           #+#    #+#              #
#    Updated: 2018/08/28 12:28:04 by mgerber          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker

NAME2 = push_swap

all: $(NAME1) $(NAME2)

lib:	
	make re -C ./libft/
	make clean -C ./libft/

FLAGS = -Wall -Wextra -Werror -c

SRCS1 = actions.c\
		checker.c\
		parse.c\
		tools.c

SRCS2 = actions.c\
		algo_tools.c\
		algo1.c\
		csort.c\
		parse.c\
		push_swap.c\
		sort_3.c\
		tools.c

OBJ1 = $(SRCS1:.c=.o)

OBJ2 = $(SRCS2:.c=.o)

$(NAME1): $(OBJ1)
	gcc $(FLAGS) $(SRCS1)
	gcc -o $(NAME1) $(OBJ1) -L. ./libft/libft.a

$(NAME2): $(OBJ2)
	gcc $(FLAGS) $(SRCS2)
	gcc -o $(NAME2) $(OBJ2) -L. ./libft/libft.a

clean:
	rm -f *.o

fclean: 	clean
	rm -rf $(NAME1)
	rm -rf $(NAME2)

re: fclean all
	make clean
