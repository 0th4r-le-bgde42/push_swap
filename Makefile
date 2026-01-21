# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mschappe <mschappe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/30 11:56:43 by ldauber           #+#    #+#              #
#    Updated: 2026/01/21 10:43:50 by mschappe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I .

RM = rm -f

SRC = \
	ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_putfloat.c \
	ft_swap.c ft_push.c ft_rotate.c ft_reverse_rotate.c ft_split.c\
	ft_utils.c ft_struct_utils.c \
	ft_small_sort.c ft_insertion_sort.c ft_bucket_sort.c ft_adaptive.c \
	ft_radix.c ft_check.c ft_error.c ft_index.c ft_join_args.c\
	ft_bench.c main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

GREEN = \033[0;32m
PINK = \033[1;35m
PURPLE = \033[0;35m
RESET = \033[0m

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) succesfully compiled !$(RESET)"

%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -I . -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo "$(PURPLE)Objects files deleted.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(PINK)Executable file deleted.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
