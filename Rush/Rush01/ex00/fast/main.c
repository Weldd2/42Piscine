/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:26:59 by amura             #+#    #+#             */
/*   Updated: 2023/08/20 22:22:35 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "main.h"
#include "fill.h"
#include "globals.h"
#include "backtracking.h"
#include "board_init.h"
#include "board_valid.h"
#include "board_checking.h"
#include "board_utilities.h"
#include "utilities.h"

int	ft_count_valid_digits(char *str)
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

void	ft_fill_array_with_digits(int *result, char *str)
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

int	*ft_get_params(char *str)
{
	int	count;
	int	*result;

	if (!str || str[0] == ' ')
		return (NULL);
	count = ft_count_valid_digits(str);
	if (count == -1)
		return (NULL);
	result = (int *)malloc(count * sizeof(int));
	if (!result)
		return (NULL);
	ft_fill_array_with_digits(result, str);
	if (result[count - 1] == -1)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

int	ft_is_finished(int board[6][6])
{
	int	x;

	x = 1;
	while (x <= 4)
	{
		if (ft_is_line_empty(board, x, TOP))
			return (0);
		if (ft_is_line_empty(board, x, LEFT))
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
	ft_create_board(board);
	arg_tab = ft_get_params(argv[1]);
	if (arg_tab == NULL)
		return (0);
	ft_init_board(board, arg_tab);
	free(arg_tab);
	ft_optimizer(board);
	ft_solve(board, 1);
	if (ft_is_finished(board))
	{
		ft_print_str("Plateau terminé. Nombre d'itérations : ");
		ft_putnbr(g_solve_compteur);
		ft_print_str("\n");
		ft_print_board(board);
	}
	else
		ft_print_str("La combinaison donnée n'a pas pu être terminée.\n");
	return (0);
}
