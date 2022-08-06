NAME = push_swap


SRCS = srcs/push_swap.c\
	   srcs/create_lsts.c\
	   srcs/free.c\
	   srcs/connect.c\
	   srcs/parse_args.c\
	   srcs/check.c\
	   srcs/utils/ft_atol.c\
	   srcs/stack_op/push.c\
	   srcs/stack_op/swap.c\
	   srcs/stack_op/rotate.c\
	   srcs/stack_op/reverse_rotate.c\
	   srcs/utils/indexing_stack.c\
	   srcs/sort_op/small_stack.c


LIBFT_DIR = ./libft

LIBFT= ./libft/libft.a

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3

.c.o:
	${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

all: ${NAME}


$(NAME): ${LIBFT_DIR} ${OBJS}
	make -C $(LIBFT_DIR)
	cp ${LIBFT} .
	$(CC) ${CFLAGS} ${OBJS} -Iinclude -L. -o push_swap -lft

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

build:
	docker build -t arch .
	docker run -ti arch
prune:
	docker system prune -a --volumes

re:	fclean all

.PHONY: bonus all clean fclean re
