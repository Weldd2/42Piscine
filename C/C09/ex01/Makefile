NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCDIR = srcs/
INCDIR = includes/

SRCS = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJS = $(addprefix $(SRCDIR),$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

$(SRCDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
