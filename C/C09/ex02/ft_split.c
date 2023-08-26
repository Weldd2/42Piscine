/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:28:11 by amura             #+#    #+#             */
/*   Updated: 2023/08/22 13:15:49 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_str_length(char *str)
{
	unsigned int	str_length;

	str_length = 0;
	while (str[str_length])
		str_length++;
	return (str_length);
}

int	has_a_doublon(char *str)
{
	int	i;
	int	j;

	if (ft_str_length(str) == 1)
		return (0);
	if (ft_str_length(str) == 0)
		return (1);
	i = -1;
	while (str[++i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
	}
	return (0);
}

int	*get_index(char *str, char *charset, int *nb_index)
{
	int	j;
	int	i;
	int	r_index;
	int	*r;

	i = -1;
	r = malloc(sizeof(int) * (ft_str_length(str)) + 1);
	r_index = 0;
	while (str[++i])
	{
		j = -1;
		while (charset[++j])
		{
			if (str[i] == charset[j])
			{
				r[r_index] = i;
				r_index++;
			}
		}
	}
	*nb_index = r_index;
	return (r);
}

char	*get_str_between_indices(char *str, int start, int end)
{
	int		i;
	int		compteur;
	char	*r;

	r = malloc(sizeof(char) * (end - start) + 1);
	i = start;
	compteur = 0;
	while (i < end)
	{
		r[compteur] = str[i];
		i++;
		compteur++;
	}
	r[compteur] = '\0';
	return (r);
}

char	**ft_split(char *str, char *charset)
{
	int		nb_index;
	int		i;
	int		*index;
	char	**r;

	i = -1;
	if (has_a_doublon(charset))
		return (NULL);
	index = get_index(str, charset, &nb_index);
	r = malloc(sizeof(char *) * nb_index + 2);
	while (++i < nb_index)
	{
		if (index[i + 1])
			r[i] = get_str_between_indices(str, index[i] + 1, index[i + 1]);
	}
	r[i] = '\0';
	return (r);
}
