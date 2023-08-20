/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:26:59 by amura             #+#    #+#             */
/*   Updated: 2023/08/20 19:51:41 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "fill.h"
#include "globals.h"
#include "backtracking.h"
#include "board_init.h"
#include "board_valid.h"
#include "board_checking.h"
#include "board_utilities.h"

int	g_solve_compteur = 0;

int	count_valid_digits(char *str)
{
	int	i;
	int	count;
	int	space_count;

	i = 0;
	count = 0;
	space_count = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			count++;
			if (space_count > 1 || (i > 0 && str[i - 1] != ' '))
				return (-1);
			space_count = 0;
		}
		else if (str[i] == ' ')
			space_count++;
		else
			return (-1);
		i++;
	}
	if (count != 16)
		return (-1);
	return (count);
}

void	fill_array_with_digits(int *result, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!(str[i] >= '1' && str[i] <= '4'))
		return ;
	while (str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] <= '4')
			result[j++] = str[i] - '0';
		i++;
	}
	if (!(str[i - 1] >= '1' && str[i - 1] <= '4'))
		result[j - 1] = -1;
}

int	*get_params(char *str)
{
	int	count;
	int	*result;

	if (!str || str[0] == ' ')
		return (NULL);
	count = count_valid_digits(str);
	if (count == -1)
		return (NULL);
	result = (int *)malloc(count * sizeof(int));
	if (!result)
		return (NULL);
	fill_array_with_digits(result, str);
	if (result[count - 1] == -1)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

int	is_finished(int board[6][6])
{
	int	x;

	x = 1;
	while (x <= 4)
	{
		if (is_line_empty(board, x, TOP))
			return (0);
		if (is_line_empty(board, x, LEFT))
			return (0);
		x++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	*arg_tab;
	int	board[6][6];

	if (argc != 2)
		return (0);
	create_board(board);
	arg_tab = get_params(argv[1]);
	if (arg_tab == NULL)
		return (0);
	init_board(board, arg_tab);
	free(arg_tab);
	optimizer(board);
	solve(board, 1, 1);
	if (is_finished(board))
	{
		printf("Plateau terminé à l'aide de %d itérations.\n", g_solve_compteur);
		print_board(board);
	}
	else
		printf("La combinaison donnée n'a pas pu être terminée.\n");
	return (0);
}
