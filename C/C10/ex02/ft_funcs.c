/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:28:07 by amura             #+#    #+#             */
/*   Updated: 2023/08/23 15:45:12 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_funcs.h"

void	ft_putstr(const char *str, int sortie)
{
	while (*str)
		write(sortie, str++, 1);
}

int	ft_get_nbr(char *str, int result)
{
	if (*str <= '9' && *str >= '0')
		return (ft_get_nbr(str + 1, (result * 10) + (*str - '0')));
	return (result);
}

int	get_option(char **argv, char char_to_detect, int argc, int *index)
{
	int	i;
	int	str_len;
	int	r;

	i = 0;
	while (argv[++i])
	{
		str_len = 0;
		if (argv[i][0] == '-' && argv[i][1] == char_to_detect)
		{
			while (argv[i][str_len])
				str_len++;
			r = ft_get_nbr(argv[i + 1], 0);
			if (r > 0)
			{
				*index = i;
				return (r);
			}
		}
	}
	return (0);
}

int	get_file_size(int file)
{
	int		compteur;
	int		r;
	char	buffer[1];

	r = 0;
	compteur = 1;
	while (compteur > 0)
	{
		compteur = read(file, buffer, sizeof(buffer));
		r += compteur;
	}
	return (r);
}
