/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:48:59 by amura             #+#    #+#             */
/*   Updated: 2023/08/20 19:09:22 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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
