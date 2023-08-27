/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:10:55 by amura             #+#    #+#             */
/*   Updated: 2023/08/27 14:23:05 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

static int	count_words(char *str, char sep)
{
	int	count;
	int	i;

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

static void	fill_result(char **result, char *str, char sep, int nb_words)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < nb_words)
	{
		k = 0;
		result[i] = malloc(50 * sizeof(char));
		if (!result[i])
			return ;
		while (str[j] == sep)
			j++;
		while (str[j] && str[j] != sep)
		{
			result[i][k] = str[j];
			k++;
			j++;
		}
		result[i][k] = '\0';
		i++;
	}
}

char	**ft_split(char *str, char sep)
{
	char	**result;
	int		nb_words;

	nb_words = count_words(str, sep);
	result = malloc((nb_words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	fill_result(result, str, sep, nb_words);
	result[nb_words] = 0;
	return (result);
}
