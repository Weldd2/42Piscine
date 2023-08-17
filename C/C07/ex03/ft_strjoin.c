/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:10:12 by amura             #+#    #+#             */
/*   Updated: 2023/08/17 21:24:31 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <stdlib.h>

// Cette fonction renvoie la longueur d'une chaîne de caractères.
static int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    char *result;
    int i;
    int j;
    int k;
    int total_length = 0;

    // Si la taille est 0, retourner une chaîne vide.
    if (size == 0)
    {
        result = (char *)malloc(1);
        result[0] = '\0';
        return result;
    }

    // Calculer la longueur totale nécessaire pour le résultat.
    for (i = 0; i < size; i++)
    {
        total_length += ft_strlen(strs[i]);
    }
    total_length += ft_strlen(sep) * (size - 1) + 1;  // Pour les séparateurs et le '\0' à la fin.

    result = (char *)malloc(total_length);
    if (!result)
        return NULL;

    k = 0;
    for (i = 0; i < size; i++)
    {
        j = 0;
        while (strs[i][j])
        {
            result[k++] = strs[i][j++];
        }
        if (i < size - 1)
        {
            j = 0;
            while (sep[j])
            {
                result[k++] = sep[j++];
            }
        }
    }
    result[k] = '\0';

    return result;
}


#include <stdio.h>
#include <unistd.h>
int	main(void)
{
	char *src = "test";
	char *dest = "test";
	char *sep = " || ";
	char *strs[2];

	strs[0] = src;
	strs[1] = dest;

	char *result;
	
	strs[0] = src;
	strs[1] = dest;
	result = ft_strjoin(2, strs, sep);
	write(1, result, ft_strlen(result));
	free(result);
}