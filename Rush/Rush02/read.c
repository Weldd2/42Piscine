/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:48:22 by amura             #+#    #+#             */
/*   Updated: 2023/08/26 21:01:33 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

void	read_0_to_20(long long nb, s_couple *couple_array)
{
	int	i;

	i = get_place(nb, couple_array);
	if (i != -1)
		write(1, couple_array[i].str_val, sizeof(couple_array[i].str_val));
}

void	read_0_to_1k(long long nb, s_couple *couple_array, long long ite)
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
		read_0_to_1k(nb % ite, couple_array, ite / 10);
	}
}

void	read_0_to_1M(long long nb, s_couple *couple_array, long long ite)
{

	if (nb <= 999)
		read_0_to_1k(nb, couple_array, ite);
	else
	{
		read_0_to_1k(nb / 1000, couple_array, ite / 1000);
		write_from_couple_array(1000, couple_array);
		read_0_to_1k(nb % ite, couple_array, 100);
	}
}

void	read_0_to_1B(long long nb, s_couple *couple_array, long long ite)
{

	if (nb <= 999999)
		read_0_to_1M(nb, couple_array, ite);
	else
	{
		read_0_to_1M(nb / 1000000, couple_array, ite / 1000000);
		write_from_couple_array(1000000, couple_array);
		read_0_to_1M(nb % ite, couple_array, 100000);
	}
}

void	read_0_to_XB(long long nb, s_couple *couple_array, long long ite)
{
	if (nb <= 999999999)
		read_0_to_1B(nb, couple_array, ite);
	else
	{
		read_0_to_1B(nb / 1000000000, couple_array, ite / 1000000000);
		write_from_couple_array(1000000000, couple_array);
		read_0_to_1B(nb % ite, couple_array, 100000000);
	}
}
