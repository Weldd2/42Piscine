/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:53:22 by amura             #+#    #+#             */
/*   Updated: 2023/08/14 16:56:01 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
		str++;
	}
}

void	print_i(int i)
{
	int	temp;

	temp = i;
	temp += '0';
	if (i >= 10)
	{
		temp = i % 10;
		temp += '0';
		i = i / 10;
		print_i(i);
	}
	write(1, &temp, 1);
}

void	print_r(int i, int j)
{
	if (i < 10)
	{
		print_i(0);
	}
	print_i(i);
	print(" ");
	if (j < 10)
	{
		print_i(0);
	}
	print_i(j);
	if (i == 98 && j == 99)
	{
	}
	else
	{
		print(", ");
	}
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 99)
	{
		j++;
		if (j == 100)
		{
			j = 0;
			i++;
		}
		print_r(i, j);
		if (i == 98 && j == 99)
		{
			break ;
		}
	}
}
