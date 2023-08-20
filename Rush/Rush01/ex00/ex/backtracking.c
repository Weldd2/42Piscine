/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:27:07 by amura             #+#    #+#             */
/*   Updated: 2023/08/20 18:27:08 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globals.h"
#include "main.h"

int	try_next_position(int board[6][6], int row, int col)
{
	if (col == 4)
	{
		return (solve(board, row + 1, 1));
	}
	return (solve(board, row, col + 1));
}

int	solve(int board[6][6], int row, int col)
{
	int	num;

	if (row == 5)
		return (is_board_valid(board));
	if (board[row][col] != 0)
	{
		return (try_next_position(board, row, col));
	}
	num = 1;
	while (num <= 4)
	{
		board[row][col] = num;
		if (is_board_valid(board) && try_next_position(board, row, col))
		{
			return (1);
		}
		g_solve_compteur++;
		board[row][col] = 0;
		num++;
	}
	return (0);
}

void	optimizer(int board[6][6])
{
	int	i;

	i = 0;
	while (i <= 4) 
	{
		fill_board_if_condition(board, i, RIGHT);
		fill_board_if_condition(board, i, LEFT);
		fill_board_if_condition(board, i, TOP);
		fill_board_if_condition(board, i, BOTTOM);
		i++;
	}
}
