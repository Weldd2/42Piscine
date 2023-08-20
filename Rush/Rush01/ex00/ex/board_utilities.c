/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:22:34 by amura             #+#    #+#             */
/*   Updated: 2023/08/20 18:27:55 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "globals.h"
#include <stdio.h>
#include <stdlib.h>

int	is_line_empty(int board[6][6], int coord, enum e_Direction d)
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

void	create_board(int board[6][6])
{
	int	i;
	int	j;

	i = 0;
	while (i < 6) 
	{
		j = 0;
		while (j < 6) 
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	print_board_with_indices(int board[6][6])
{
	int	i;
	int	j;

	i = 0;
	while (i < 6) 
	{
		while (j < 6)
		{
			printf("%d ", board[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_board(int board[6][6])
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			if (!(i == 0 || j == 0 || i == 5 || j == 5))
				printf("%d", board[i][j]);
			if (i != 0 && i != 5 && j < 4 && j != 0)
				printf(" ");
			j++;
		}
		if (i != 0 && i != 5)
			printf("\n");
		i++;
	}
}

void	init_board(int board[6][6], int *params)
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			if (i == 0 && j > 0 && j < 5) 
				board[i][j] = params[i + j - 1];
			else if (i == 5 && j > 0 && j < 5) 
				board[i][j] = params[3 + j];
			else if (j == 0 && i > 0 && i < 5) 
				board[i][j] = params[7 + i];
			else if (j == 5 && i > 0 && i < 5) 
				board[i][j] = params[11 + i];
			else 
				board[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	get_building_indice(int board[6][6], int coord, enum e_Direction d)
{
	if (d == LEFT)
		return (board[coord][0]);
	if (d == RIGHT)
		return (board[coord][5]);
	if (d == TOP)
		return (board[0][coord]);
	if (d == BOTTOM)
		return (board[5][coord]);
}

int	has_a_doublon(int board[6][6], int coord, enum e_Direction d)
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

int	check_left(int board[6][6], int coord, int max)
{
	int	compteur;
	int	x;

	compteur = 1;
	x = 2;
	while (x <= 4)
	{
		if (max < board[coord][x])
		{
			max = board[coord][x];
			compteur++;
		}
		x++;
	}
	return (compteur);
}

int	check_right(int board[6][6], int coord, int max)
{
	int	compteur;
	int	x;

	compteur = 1;
	x = 3;
	while (x >= 1)
	{
		if (max < board[coord][x])
		{
			max = board[coord][x];
			compteur++;
		}
		x--;
	}
	return (compteur);
}

int	check_top(int board[6][6], int coord, int max)
{
	int	compteur;
	int	x;

	compteur = 1;
	x = 2;
	while (x <= 4)
	{
		if (max < board[x][coord])
		{
			max = board[x][coord];
			compteur++;
		}
		x++;
	}
	return (compteur);
}

int	check_bottom(int board[6][6], int coord, int max)
{
	int	compteur;
	int	x;

	compteur = 1;
	x = 3;
	while (x >= 1)
	{
		if (max < board[x][coord])
		{
			max = board[x][coord];
			compteur++;
		}
		x--;
	}
	return (compteur);
}

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

void	fill_vertical(int board[6][6], int coord, int start_value, int step)
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

int	fill_board(int board[6][6], int starting_coord, enum e_Direction d)
{
	if (d == RIGHT)
		fill_horizontal(board, starting_coord, 4, -1);
	else if (d == LEFT)
		fill_horizontal(board, starting_coord, 1, 1);
	else if (d == TOP)
		fill_vertical(board, starting_coord, 1, 1);
	else if (d == BOTTOM)
		fill_vertical(board, starting_coord, 4, -1);
	return (0);
}
