/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:47:31 by amura             #+#    #+#             */
/*   Updated: 2023/08/20 22:16:39 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "globals.h"
#include "fill.h"

void	ft_print_str(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		if (n == -2147483648)
		{
			write(1, "2147483648", 10);
			return ;
		}
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
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
