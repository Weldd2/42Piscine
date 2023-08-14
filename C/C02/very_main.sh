#!/bin/bash

# Initialiser le fichier main.c
echo "#include <stdio.h>" > main.c

# Pour chaque fichier .c dans les sous-répertoires
find . -type f -name "*.c" | while read -r file; do
    # Extraire le nom du fichier (sans extension) pour avoir le nom de la fonction
    function_name=$(basename "$file" .c)

    # Extraire la déclaration de la fonction à partir du fichier .c
    # Utiliser l'option -P pour permettre des séquences d'échappement comme \t
    declaration=$(grep -P "^[a-zA-Z_][a-zA-Z0-9_]*\t[*]?\s*$function_name\(" "$file")

    # Ajouter la déclaration de la fonction dans main.c
    echo "$declaration;" >> main.c
done

# Finaliser le main.c avec une fonction main
cat << EOF >> main.c
int	main() {
	// Ajoutez des tests ici si nécessaire
	char	str[5] = "abcde";
EOF

# Ajouter les appels à la fonction après la fonction main
find . -type f -name "*.c" | while read -r file; do
    function_name=$(basename "$file" .c)
    echo "	$function_name(str);" >> main.c
done

# Fermer le corps de la fonction main
echo "	printf(\"%s\", str);" >> main.c
echo "	return 0;" >> main.c
echo "}" >> main.c

echo "Fichier main.c créé avec succès!"
