/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:24:12 by amura             #+#    #+#             */
/*   Updated: 2023/08/27 11:11:03 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

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

t_couple	*fcontent_to_couple(char *str)
{
	t_couple	*couple;
	char		**result;
	char		**temp;
	int			i;
	result = ft_split(str, '\n');
	if (!result)
		return (NULL);
	couple = malloc((32) * sizeof(t_couple));
	if (!couple)
		return (NULL);
	i = 0;
	while (result[i])
	{
		temp = ft_split(result[i], ':');
		if (temp)
		{
			couple[i].val = ft_atoi(temp[0], 0);
			couple[i].str_val = temp[1];
			free(temp);
		}
		free(result[i]);
		i++;
	}
	free(result);
	return (couple);
}
t_couple	*read_dict(char *dict_name)
{
	int	file;
	char*	buffer;
	int	dict_size;
	int	compteur;
	dict_size = get_dict_size(dict_name);
	if (dict_size == 0)
		return (NULL);
	buffer = malloc(sizeof(char) * dict_size);
	file = open(dict_name, O_RDONLY);
	if (!file)
		return (NULL);
	while (1)
	{
		compteur = read(file, buffer, dict_size);
		if (compteur <= 0)
			break ;
	}
	return (fcontent_to_couple(buffer));
}
