/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:53:22 by amura             #+#    #+#             */
/*   Updated: 2023/08/10 22:23:16 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_str(char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
		str++;
	}
}

void	print_int(int i)
{
	int	temp;

	temp = i;
	temp += '0';
	if (i >= 10)
	{
		temp = i % 10;
		temp += '0';
		i = i / 10;
		print_int(i);
	}
	write(1, &temp, 1);
}

void	print_result(int i, int j)
{
	if (i < 10)
	{
		print_int(0);
	}
	print_int(i);
	print_str(" ");
	if (j < 10)
	{
		print_int(0);
	}
	print_int(j);
	if (i == 99 && j == 99)
	{
	}
	else
	{
		print_str(", ");
	}
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 100)
	{
		j++;
		if (j == 100)
		{
			j = 0;
			i++;
		}
		print_result(i, j);
		if (i == 99 && j == 99)
		{
			break ;
		}
	}
}
