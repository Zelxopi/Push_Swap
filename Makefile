# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/04 12:49:31 by mtrembla          #+#    #+#              #
#    Updated: 2022/09/01 13:53:58 by mtrembla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =	dlist.c \
		main.c \
		parsing.c \
		utils.c \
		moves.c \
		index.c \
		sort.c \

OBJ =	$(SRC:.c=.o)

SDIR = src
ODIR = obj
SFIX = $(addprefix $(SDIR)/, $(SRC))
OFIX = $(addprefix $(ODIR)/, $(OBJ))

CC = gcc
FLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

LIBFT =	./libft/libft.a

$(ODIR)/%.o: $(SDIR)/%.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\033[92m.\033[0m\c"

$(NAME): $(ODIR) $(OFIX)
	@$(MAKE)  lib -C libft
	@$(CC) $(FLAGS) $(OFIX) -o $(NAME) $(LIBFT)

$(ODIR): 
	@mkdir -p $(ODIR)

all: $(NAME)

clean:
	@$(RM) $(OFIX) $(ODIR)
	@echo "🧹"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re