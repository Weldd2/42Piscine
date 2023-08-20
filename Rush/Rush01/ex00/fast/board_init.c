/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:48:59 by amura             #+#    #+#             */
/*   Updated: 2023/08/20 20:54:33 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_create_board(int board[6][6])
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

void	ft_print_board_with_indices(int board[6][6])
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < 6) 
	{
		while (j < 6)
		{
			temp = (board[i][j] + '0');
			write(1, &temp, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_print_board(int board[6][6])
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			if (!(i == 0 || j == 0 || i == 5 || j == 5))
			{
				temp = (board[i][j] + '0');
				write(1, &temp, 1);
			}
			if (i != 0 && i != 5 && j < 4 && j != 0)
				write(1, " ", 1);
			j++;
		}
		if (i != 0 && i != 5)
			write(1, "\n", 1);
		i++;
	}
}

void	ft_init_board(int board[6][6], int *params)
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
