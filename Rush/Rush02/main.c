/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:48:25 by amura             #+#    #+#             */
/*   Updated: 2023/08/26 15:10:29 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	get_dict_size(char *dict_name)
{
	int		file;
	int		size;
	char	buffer[16];

	size = 0;
	file = open(dict_name, O_RDONLY);
	if (file < 0)
		return (0);
	while (read(file, buffer, sizeof(buffer)) > 0)
		size += sizeof(buffer);
	close(file);
	return (size);
}

s_couple	*fcontent_to_couple(char *str)
{
	s_couple	*couple;
	char		**result;
	char		**temp;
	int			i;

	result = ft_split(str, '\n');
	if (!result)
		return (NULL);
	couple = malloc((32) * sizeof(s_couple));
	if (!couple)
		return (NULL);
	i = 0;
	while (result[i])
	{
		temp = ft_split(result[i], ':');
		if (temp)
		{
			couple[i].val = temp[0];
			couple[i].str_val = temp[1];
			free(temp);
		}
		free(result[i]);
		i++;
	}
	free(result);
	return (couple);
}

s_couple	*read_dict(char *dict_name)
{
	int	file;
	char*	buffer;
	int	dict_size;
	int	compteur;

	dict_size = get_dict_size(dict_name);
	buffer = malloc(sizeof(char) * dict_size);
	file = open(dict_name, O_RDONLY);
	if (!file)
		return NULL;
	while (1)
	{
		compteur = read(file, buffer, dict_size);
		if (compteur == 0)
			break ;
	}
	return fcontent_to_couple(buffer);
}

int main(void)
{
	char		*dict_name = "numbers.dict";
	s_couple	*couple_array;
	int			i;

	couple_array = read_dict(dict_name);
	if (!couple_array)
	{
		printf("Erreur lors de la lecture du dictionnaire.\n");
		return (1);
	}

	// Afficher les paires val: str_val
	i = 0;
	while (couple_array[i].val != NULL && couple_array[i].str_val != NULL)
	{
		printf("Val: %s, Str_val: %s\n", couple_array[i].val, couple_array[i].str_val);
		i++;
	}
	
	return (0);
}
