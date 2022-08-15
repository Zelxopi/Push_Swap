# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/04 12:49:31 by mtrembla          #+#    #+#              #
#    Updated: 2022/08/14 12:22:34 by mtrembla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =	dlist.c \
		main.c \
		parsing.c \
		utils.c \
		moves.c \

OBJ =	$(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT =	./libft/libft.a

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\033[92m.\033[0m\c"

$(NAME): $(OBJ) $(SRC)
	@$(MAKE) -C libft
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

clean:
	@$(MAKE) fclean -C libft
	@$(RM) $(OBJ) 

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re