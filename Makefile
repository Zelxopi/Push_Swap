# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/04 12:49:31 by mtrembla          #+#    #+#              #
#    Updated: 2022/08/31 15:06:09 by mtrembla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =	dlist.c \
		main.c \
		parsing.c \
		utils.c \
		moves.c \
		index.c \

OBJS =	$(SRCS:.c=.o)

SDIR = srcs
ODIR = objs
SFIX = $(addprefix $(SDIR)/, $(SRCS))
OFIX = $(addprefix $(ODIR)/, $(OBJS))

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
	mkdir -p $(ODIR)

all: $(NAME)

clean:
	@$(RM) $(OFIX) $(ODIR)
	@echo "🧹"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re