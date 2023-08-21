# Nom de la librairie
NAME = libft.a

# Compilateur
CC = gcc
# Flags pour le compilateur
CFLAGS = -Wall -Wextra -Werror

# Dossiers des sources et headers
SRCDIR = srcs/
INCDIR = includes/

# Liste des fichiers sources et objets
SRCS = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJS = $(addprefix $(SRCDIR),$(SRCS:.c=.o))

# Règle par défaut
all: $(NAME)

# Création de la librairie
$(NAME): $(OBJS)
	ar rcs $@ $^

# Pattern pour compiler chaque fichier source en fichier objet
$(SRCDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJS)

# Nettoyage complet
fclean: clean
	rm -f $(NAME)

# Re-compilation
re: fclean all

.PHONY: all clean fclean re
