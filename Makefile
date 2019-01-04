# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drdraugr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/02 12:58:40 by variya            #+#    #+#              #
#    Updated: 2019/01/04 18:52:51 by drdraugr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

SRC=main.c read_elems.c map_for_elems.c fillit.c check_elems.c
LIBFT=./libft
OBJ=$(SRC:.c=.o)
INC=./

all: $(NAME)
	
$(NAME):
	@make -C $(LIBFT)
	@gcc -Wall -Wextra -Werror -g -I$(INC) -c $(SRC)
	@gcc $(OBJ) -L $(LIBFT) -lft -o $(NAME)

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
