/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:22:34 by amura             #+#    #+#             */
/*   Updated: 2023/08/20 20:55:00 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "globals.h"
#include <stdlib.h>

int	ft_is_line_empty(int board[6][6], int coord, enum e_Direction d)
{
	int	i;

	i = 0;
	while (i <= 4)
	{
		if (d == RIGHT || d == LEFT)
			if (board[coord][i] == 0)
				return (1);
		if (d == TOP || d == BOTTOM)
			if (board[i][coord] == 0)
				return (1);
		i++;
	}
	return (0);
}

int	ft_get_building_indice(int board[6][6], int coord, enum e_Direction d)
{
	if (d == LEFT)
		return (board[coord][0]);
	if (d == RIGHT)
		return (board[coord][5]);
	if (d == TOP)
		return (board[0][coord]);
	if (d == BOTTOM)
		return (board[5][coord]);
	return (0);
}

int	ft_has_a_doublon(int board[6][6], int coord, enum e_Direction d)
{
	int	x;
	int	z;

	x = 1;
	while (x <= 4)
	{
		z = x + 1;
		while (z <= 4)
		{
			if (d == RIGHT || d == LEFT)
			{
				if (board[coord][x] == board[coord][z])
					return (0);
			}
			else if (d == TOP || d == BOTTOM)
			{
				if (board[x][coord] == board[z][coord])
					return (0);
			}
			z++;
		}
		x++;
	}
	return (1);
}
