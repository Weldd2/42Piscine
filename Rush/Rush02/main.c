/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:48:25 by amura             #+#    #+#             */
/*   Updated: 2023/08/26 15:26:28 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

	i = 0;
	while (i < 32)
	{
		printf("Val: %d, Str_val: %s\n", couple_array[i].val, couple_array[i].str_val);
		i++;
	}
	
	return (0);
}
