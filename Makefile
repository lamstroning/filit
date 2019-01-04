# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drdraugr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/02 12:58:40 by variya            #+#    #+#              #
#    Updated: 2019/01/02 17:11:54 by variya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

SRC=*.c
LIBFT=./libft
OBJ=$(SRC:.c=.o)
INC=./

all: $(NAME)
	
$(NAME):
	@make -C $(LIBFT)
	@gcc -Wall -Wextra -Werror -I$(INC) -c $(SRC)
	@gcc $(OBJ) -L $(LIBFT) -lft -o $(NAME)

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
