/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:48:25 by amura             #+#    #+#             */
/*   Updated: 2023/08/26 20:15:51 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	get_place(int nb, s_couple *couple_array)
{
	int	i;
	
	i = -1;
	while(++i < 32)
	{
		if (couple_array[i].val == (nb))
			return (i);
	}
	return (-1);
}

void	write_from_couple_array(int nb, s_couple *couple_array)
{
	int	i;

	i = get_place(nb, couple_array);
	if (i != -1)
		write(1, couple_array[i].str_val, sizeof(couple_array[i].str_val));
}

void	read_0_to_20(int nb, s_couple *couple_array)
{
	int	i;

	i = get_place(nb, couple_array);
	if (i != -1)
		write(1, couple_array[i].str_val, sizeof(couple_array[i].str_val));
}

void	read_0_to_999(int nb, s_couple *couple_array, int ite)
{
	if (nb <= 20)
		read_0_to_20(nb, couple_array);
	else
	{
		if (nb > 99)
		{
			read_0_to_20((nb / ite), couple_array);
			write_from_couple_array(ite, couple_array);
		}
		else
			write_from_couple_array((nb / ite) * ite, couple_array);
		read_0_to_999(nb % ite, couple_array, ite / 10);
	}
}

void	read_0_to_999999(int nb, s_couple *couple_array, int ite)
{

	if (nb <= 999)
		read_0_to_999(nb, couple_array, ite);
	else
	{
		read_0_to_999(nb / 1000, couple_array, ite / 1000);
		write_from_couple_array(1000, couple_array);
		read_0_to_999(nb % ite, couple_array, 100);
	}
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
	read_0_to_999999(8151, couple_array, 1000);
	write(1, "\n", 1);
	return (0);
}
