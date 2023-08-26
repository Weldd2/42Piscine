/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:48:25 by amura             #+#    #+#             */
/*   Updated: 2023/08/26 21:01:28 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

int main(int argc, char **argv)
{
	char		*dict_name = "numbers.dict";
	s_couple	*couple_array;
	int	number;


	couple_array = read_dict(dict_name);
	if (!couple_array)
	{
		printf("Erreur lors de la lecture du dictionnaire.\n");
		return (1);
	}

	if (argc == 2)
	{
		number = ft_atoi(argv[1], 0);
		read_0_to_XB(number, couple_array, get_ite(number));
	}

	write(1, "\n", 1);
	return (0);
}
