/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:27:07 by amura             #+#    #+#             */
/*   Updated: 2023/08/20 22:23:22 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "board_valid.h"
#include "board_init.h"
#include "fill.h"
#include "main.h"
#include "backtracking.h"
#include "globals.h"

t_Combination	g_possible_combinations[PAIR_COUNT][MAX_COMBINATIONS] = {
{{3, 4, 1, 2}, {2, 1, 4, 3}, {1, 4, 2, 3}, {3, 1, 4, 2}, {3, 2, 4, 1}},
{{1, 2, 4, 3}, {1, 3, 4, 2}, {2, 3, 4, 1}},
{{3, 4, 2, 1}, {2, 4, 3, 1}, {1, 4, 3, 2}},
{{3, 1, 2, 4}, {3, 2, 1, 4}},
{{4, 2, 1, 3}, {4, 1, 2, 3}},
{{1, 3, 2, 4}, {2, 3, 1, 4}, {2, 1, 3, 4}},
{{4, 2, 3, 1}, {4, 1, 3, 2}, {4, 3, 1, 2}},
{{4, 3, 2, 1}},
{{1, 2, 3, 4}}
};

t_Indices		g_pairs[PAIR_COUNT] = {
{2, 2},
{3, 2},
{2, 3},
{2, 1},
{1, 2},
{3, 1},
{1, 3},
{1, 4},
{4, 1}
};

int				g_solve_compteur = 0;

int				g_num_combinations[PAIR_COUNT] = {5, 3, 3, 2, 2, 3, 3, 1, 1};

void	ft_set_row(int board[6][6], int row, t_Combination combo)
{
	int	col;

	col = 1;
	while (col <= 4)
	{
		board[row][col] = combo.values[col - 1];
		col++;
	}
}

void	ft_unset_row(int board[6][6], int row)
{
	int	col;

	col = 1;
	while (col <= 4)
	{
		board[row][col] = 0;
		col++;
	}
}

int	ft_try_comb(int board[6][6], int row, t_Combination *c, int n_for_pair)
{
	int	col;
	int	i;

	i = 0;
	while (i < n_for_pair)
	{
		ft_set_row(board, row, c[i]);
		g_solve_compteur++;
		if (ft_is_board_valid(board))
		{
			if (row == 4 || ft_solve(board, row + 1))
			{
				return (1);
			}
		}
		ft_unset_row(board, row);
		i++;
	}
	return (0);
}

int	ft_solve(int board[6][6], int row)
{
	int				n_for_pair;
	t_Combination	*c;

	if (row == 5)
		return (ft_is_board_valid(board));
	c = ft_get_possible_c(board[row][0], board[row][5], &n_for_pair);
	if (!c)
		return (0);
	return (ft_try_comb(board, row, c, n_for_pair));
}

t_Combination	*ft_get_possible_c(int from, int to, int *num_combo)
{
	int	i;

	i = 0;
	while (i < PAIR_COUNT)
	{
		if (g_pairs[i].from == from && g_pairs[i].to == to)
		{
			*num_combo = g_num_combinations[i];
			return (g_possible_combinations[i]);
		}
		i++;
	}
	*num_combo = 0;
	return (NULL);
}
