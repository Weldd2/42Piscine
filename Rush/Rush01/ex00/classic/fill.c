/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:47:47 by amura             #+#    #+#             */
/*   Updated: 2023/08/20 20:56:10 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globals.h"
#include "fill.h"
#include "board_utilities.h"

void	fill_horizontal(int board[6][6], int coord, int start_value, int step)
{
	int	i;

	i = 1;
	while (i <= 4)
	{
		board[coord][i] = start_value;
		start_value += step;
		i++;
	}
}

void	ft_fill_vertical(int board[6][6], int coord, int start_value, int step)
{
	int	i;

	i = 1;
	while (i <= 4)
	{
		board[i][coord] = start_value;
		start_value += step;
		i++;
	}
}

int	ft_fill_board(int board[6][6], int starting_coord, enum e_Direction d)
{
	if (d == RIGHT)
		fill_horizontal(board, starting_coord, 4, -1);
	else if (d == LEFT)
		fill_horizontal(board, starting_coord, 1, 1);
	else if (d == TOP)
		ft_fill_vertical(board, starting_coord, 1, 1);
	else if (d == BOTTOM)
		ft_fill_vertical(board, starting_coord, 4, -1);
	return (0);
}

void	ft_fill_board_if_condition(int board[6][6], int i, int direction)
{
	if (ft_get_building_indice(board, i, direction) == 4)
	{
		ft_fill_board(board, i, direction);
	}
	else if (ft_get_building_indice(board, i, direction) == 1)
	{
		if (direction == RIGHT)
			board[i][4] = 4;
		else if (direction == LEFT)
			board[i][1] = 4;
		else if (direction == TOP)
			board[1][i] = 4;
		else if (direction == BOTTOM)
			board[4][i] = 4;
	}
}
