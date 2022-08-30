# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/04 12:49:31 by mtrembla          #+#    #+#              #
#    Updated: 2022/08/30 18:17:49 by mtrembla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =	srcs/dlist.c \
		srcs/main.c \
		srcs/parsing.c \
		srcs/utils.c \
		srcs/moves.c \
		srcs/index.c \

OBJ =	$(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

LIBFT =	./libft/libft.a

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\033[92m.\033[0m\c"

$(NAME): $(OBJ) $(SRC)
	@$(MAKE)  lib -C libft
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

clean:
	@$(RM) $(OBJ)
	@echo "🧹"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re