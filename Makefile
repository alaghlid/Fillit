# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alaghlid <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 03:07:56 by alaghlid          #+#    #+#              #
#    Updated: 2019/06/29 19:29:35 by alaghlid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
OBJECTS = main.o reader.o checker.o tet_list.o position.o map.o backtrack.o  get_next_line.o ft_*.o
SRC = main.c reader.c checker.c tet_list.c position.c map.c backtrack.c  get_next_line/get_next_line.c get_next_line/libft/ft_*.c
FLAGS = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME) :
	gcc $(FLAGS) $(SRC)
	gcc -o $(NAME) $(OBJECTS)

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
