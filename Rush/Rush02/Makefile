CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = main.c atoi.c print_number.c read_dict.c split.c tool.c
OBJ = $(SRC:.c=.o)
NAME = rush-02

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
