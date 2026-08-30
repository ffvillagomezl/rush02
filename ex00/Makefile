
NAME		= rush-02
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
SRCS		= main.c dict_iterator.c ft_write_num.c ft_strlen.c \
			  ft_evaluate_numbers.c ft_divide_in_groups.c \
			  ft_alloc_group.c ft_zero_check.c ft_is_numeric.c

OBJS		= $(SRCS:.c=.o)
HEADER		= headers.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re