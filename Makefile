# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 15:06:11 by trerolle          #+#    #+#              #
#    Updated: 2022/04/07 15:13:04 by trerolle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc 

NAME = push_swap

FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT_A = libft.a
LIBFT = -L. -lft


BIN = bin

SOURCE = operations.c \
		 push_swap.c\
		 ./utils/lits.c\



OBJS = $(patsubst %,$(BIN)/%,$(notdir $(SOURCE:.c=.o)))

$(BIN)/%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

${NAME}: ${OBJS}
	@make -C ${LIBFT_DIR}/
	@cp ${LIBFT_DIR}/$(LIBFT_A) .
	$(CC)  ${OBJS} $(LIBFT) -o $(NAME)
	@echo "$(GREEN)$(NAME) sucessfully created$(RESET)"

clean:
	@rm -f $(OBJS)
	@make -C ${LIBFT_DIR} clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT_A)
	@make -C ${LIBFT_DIR} fclean

re: fclean all

.PHONY: fclean re all clean bonus

