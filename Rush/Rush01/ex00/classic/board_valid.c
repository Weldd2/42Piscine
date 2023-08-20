/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:45:54 by amura             #+#    #+#             */
/*   Updated: 2023/08/20 20:56:00 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "globals.h"
#include "board_checking.h"
#include "board_valid.h"
#include "board_valid.h"
#include "board_utilities.h"

int	ft_is_indice_valid(int board[6][6], int coord, enum e_Direction d)
{
	int	compteur;
	int	max;

	if (d == LEFT)
	{
		max = board[coord][1];
		compteur = ft_check_left(board, coord, max);
	}
	else if (d == RIGHT)
	{
		max = board[coord][4];
		compteur = ft_check_right(board, coord, max);
	}
	else if (d == TOP)
	{
		max = board[1][coord];
		compteur = ft_check_top(board, coord, max);
	}
	else if (d == BOTTOM)
	{
		max = board[4][coord];
		compteur = ft_check_bottom(board, coord, max);
	}
	return (compteur == ft_get_building_indice(board, coord, d));
}

int	ft_is_column_valid(int board[6][6], int x)
{
	if (!ft_is_line_empty(board, x, TOP))
	{
		if (!ft_has_a_doublon(board, x, TOP))
			return (0);
		if (!ft_is_indice_valid(board, x, TOP))
			return (0);
		if (!ft_is_indice_valid(board, x, BOTTOM))
			return (0);
	}
	return (1);
}

int	ft_is_line_valid(int board[6][6], int y)
{
	if (!ft_is_line_empty(board, y, LEFT))
	{
		if (!ft_has_a_doublon(board, y, LEFT))
			return (0);
		if (!ft_is_indice_valid(board, y, LEFT))
			return (0);
		if (!ft_is_indice_valid(board, y, RIGHT))
			return (0);
	}
	return (1);
}

int	ft_ft_is_board_valid(int board[6][6])
{
	int	y;
	int	x;

	y = 1;
	while (y <= 4)
	{
		if (!ft_is_line_valid(board, y))
			return (0);
		x = 1;
		while (x <= 4)
		{
			if (!ft_is_column_valid(board, x))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
