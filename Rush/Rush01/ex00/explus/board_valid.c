/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:45:54 by amura             #+#    #+#             */
/*   Updated: 2023/08/20 19:15:53 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "globals.h"
#include "board_checking.h"
#include "board_valid.h"
#include "board_valid.h"
#include "board_utilities.h"

int	is_indice_valid(int board[6][6], int coord, enum e_Direction d)
{
	int	compteur;
	int	max;

	if (d == LEFT)
	{
		max = board[coord][1];
		compteur = check_left(board, coord, max);
	}
	else if (d == RIGHT)
	{
		max = board[coord][4];
		compteur = check_right(board, coord, max);
	}
	else if (d == TOP)
	{
		max = board[1][coord];
		compteur = check_top(board, coord, max);
	}
	else if (d == BOTTOM)
	{
		max = board[4][coord];
		compteur = check_bottom(board, coord, max);
	}
	return (compteur == get_building_indice(board, coord, d));
}

int	is_column_valid(int board[6][6], int x)
{
	if (!is_line_empty(board, x, TOP))
	{
		if (!has_a_doublon(board, x, TOP))
			return (0);
		if (!is_indice_valid(board, x, TOP))
			return (0);
		if (!is_indice_valid(board, x, BOTTOM))
			return (0);
	}
	return (1);
}

int	is_line_valid(int board[6][6], int y)
{
	if (!is_line_empty(board, y, LEFT))
	{
		if (!has_a_doublon(board, y, LEFT))
			return (0);
		if (!is_indice_valid(board, y, LEFT))
			return (0);
		if (!is_indice_valid(board, y, RIGHT))
			return (0);
	}
	return (1);
}

int	is_board_valid(int board[6][6])
{
	int	y;
	int	x;

	y = 1;
	while (y <= 4)
	{
		if (!is_line_valid(board, y))
			return (0);
		x = 1;
		while (x <= 4)
		{
			if (!is_column_valid(board, x))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
