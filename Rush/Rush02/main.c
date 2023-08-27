/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 22:24:37 by amura             #+#    #+#             */
/*   Updated: 2023/08/27 14:41:41 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

t_couple	*open_dict(char *str)
{
	t_couple	*couple_array;

	couple_array = read_dict(str);
	return (couple_array);
}

int	ft_print_error(t_couple	*couple_array, int number)
{
	if (!couple_array)
	{
		write(2, "Dict Error", 11);
		return (1);
	}
	if (number < 0)
	{
		write(2, "Error", 5);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_couple	*couple_array;
	long long	number;

	if (argc == 3)
	{
		number = ft_atoi(argv[2], 0);
		couple_array = open_dict(argv[1]);
	}
	else if (argc == 2)
	{
		number = ft_atoi(argv[1], 0);
		couple_array = open_dict("numbers.dict");
	}
	else
		return (0);
	if (!ft_print_error(couple_array, number))
		print_number(number, couple_array);
	free(couple_array);
	write(1, "\n", 1);
	return (0);
}
