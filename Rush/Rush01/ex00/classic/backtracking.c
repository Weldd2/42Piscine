/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:27:07 by amura             #+#    #+#             */
/*   Updated: 2023/08/20 20:56:10 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "board_valid.h"
#include "fill.h"
#include "main.h"
#include "backtracking.h"

int	ft_try_next_position(int board[6][6], int row, int col)
{
	if (col == 4)
	{
		return (ft_solve(board, row + 1, 1));
	}
	return (ft_solve(board, row, col + 1));
}

int	ft_solve(int board[6][6], int row, int col)
{
	int	num;

	if (row == 5)
		return (ft_ft_is_board_valid(board));
	if (board[row][col] != 0)
	{
		return (ft_try_next_position(board, row, col));
	}
	num = 1;
	while (num <= 4)
	{
		board[row][col] = num;
		if (ft_ft_is_board_valid(board) && ft_try_next_position(board, row, col))
		{
			return (1);
		}
		g_ft_solve_compteur++;
		board[row][col] = 0;
		num++;
	}
	return (0);
}

void	ft_optimizer(int board[6][6])
{
	int	i;

	i = 0;
	while (i <= 4) 
	{
		ft_fill_board_if_condition(board, i, RIGHT);
		ft_fill_board_if_condition(board, i, LEFT);
		ft_fill_board_if_condition(board, i, TOP);
		ft_fill_board_if_condition(board, i, BOTTOM);
		i++;
	}
}
