NAME		= rush-02
CC			= cc
# Banderas estrictas de 42, más -g para facilitar el uso de gdb o valgrind
CFLAGS		= -Wall -Wextra -Werror -g

SRCS		= main.c ft_dictonary_iterator.c ft_write_num.c ft_strlen.c \
			  ft_evaluate_numbers.c ft_divide_in_groups.c \
			  ft_alloc_group.c ft_zero_check.c ft_is_numeric.c

OBJS		= $(SRCS:.c=.o)
HEADER		= headers.h

all: $(NAME)

# Enlaza los objetos creados para generar el ejecutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Regla de compilación para cada archivo .c a .o
# El prerequisito $(HEADER) recompila todo si modificas el .h
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpia los binarios intermedios (.o)
clean:
	rm -f $(OBJS)

# Limpia los binarios intermedios y el ejecutable principal
fclean: clean
	rm -f $(NAME)

# Recompila todo desde cero
re: fclean all

# Protege las reglas para que no colisionen con archivos reales del mismo nombre
.PHONY: all clean fclean re