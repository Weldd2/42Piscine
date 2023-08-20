/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:58:37 by amura             #+#    #+#             */
/*   Updated: 2023/08/20 19:10:42 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "board_checking.h"

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
