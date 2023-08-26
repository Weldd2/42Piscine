/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 22:24:37 by amura             #+#    #+#             */
/*   Updated: 2023/08/27 00:11:36 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

t_couple	*open_dict(char *str)
{
	char	*dict_name;
	t_couple	*couple_array;

	dict_name = str;
	couple_array = read_dict(dict_name);
	return (couple_array);
}

void	ft_print_error(void)
{
	write(1, "Dict Error\n", 12);
}

int	main(int argc, char **argv)
{
	char		*dict_name;
	t_couple	*couple_array;
	long long	number;
	char		dict_name[50];

	if (argc == 3)
	{
		dict_name = argv[1];
		number = ft_atoi(argv[2], 0);
	}
	if (argc == 2)
	{
		dict_name = "numbers.dict";
		number = ft_atoi(argv[1], 0);
	}
	couple_array = open_dict(argv[1]);
	if (!couple_array)
	{
		ft_print_error();
		return (0);
	}
	print_number(number, couple_array);
	write(1, "\n", 1);
	return (0);
}
