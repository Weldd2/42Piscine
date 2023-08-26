/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:10:55 by amura             #+#    #+#             */
/*   Updated: 2023/08/26 15:16:16 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split.h"

int	count_words(char *str, char sep)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != sep)
		{
			count++;
			while (str[i] && str[i] != sep)
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char *str, char sep)
{
	char	**result;
	int		i;
	int		j;
	int		k;
	int		nb_words;

	nb_words = count_words(str, sep);
	if (!(result = (char **)malloc((nb_words + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < nb_words)
	{
		k = 0;
		if (!(result[i] = malloc(50 * sizeof(char))))  // Taille fixe pour cet exemple
			return (NULL);
		while (str[j] == sep)
			j++;
		while (str[j] && str[j] != sep)
			result[i][k++] = str[j++];
		result[i][k] = '\0';
		i++;
	}
	result[nb_words] = 0;
	return (result);
}