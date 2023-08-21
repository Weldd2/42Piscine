gcc -c ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
ar rcs libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
rm ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
#r remplace ou ajoute des fichiers à l'archive
#c crée l'archive si elle n'existe pas
#s crée un index pour la recherche rapide de symboles dans la bibliothèque