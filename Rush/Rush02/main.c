/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:48:25 by amura             #+#    #+#             */
/*   Updated: 2023/08/26 16:27:27 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	read_number(int nb, s_couple *couple_array, int ite)
{
	int	i;
	int	temp;

	temp = nb / ite;
	i = 0;
	while(i < 32)
	{
		if (couple_array[i].val == temp * ite)
		{
			write(1, couple_array[i].str_val, sizeof(couple_array[i].str_val));
			break ;
		}
		i++;
	}
	if (nb % 10 != 0 && nb > 10)
		read_number(nb % 10, couple_array, ite / 10);
}

int main(void)
{
	char		*dict_name = "numbers.dict";
	s_couple	*couple_array;

	couple_array = read_dict(dict_name);
	if (!couple_array)
	{
		printf("Erreur lors de la lecture du dictionnaire.\n");
		return (1);
	}
	read_number(35, couple_array, 10);
	write(1, "\n", 1);
	return (0);
}
