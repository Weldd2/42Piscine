/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:50:25 by amura             #+#    #+#             */
/*   Updated: 2023/08/26 21:01:36 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

int	get_place(long long nb, s_couple *couple_array)
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

void	write_from_couple_array(long long nb, s_couple *couple_array)
{
	int	i;

	i = get_place(nb, couple_array);
	if (i != -1)
		write(1, couple_array[i].str_val, sizeof(couple_array[i].str_val));
}

long long	get_ite(long long nb)
{
	long long	ite;

	ite = 1;
	while (nb > 10)
	{
		ite *= 10;
		nb /= 10;
	}
	return (ite);
}
