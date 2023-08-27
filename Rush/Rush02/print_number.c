/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 23:56:28 by amura             #+#    #+#             */
/*   Updated: 2023/08/27 11:19:03 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

void	print_from_dict(long long num, t_couple *couple_array)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (couple_array[i].val == num)
		{
			ft_putstr(couple_array[i].str_val);
			return ;
		}
		i++;
	}
}

void	print_unit(long long num, t_couple *couple_array)
{
	print_from_dict(num, couple_array);
}

void	print_tens(long long num, t_couple *couple_array)
{
	if (num >= 20)
	{
		print_from_dict(num - (num % 10), couple_array);
		if (num % 10)
			print_unit(num % 10, couple_array);
	}
	else if (num >= 11 && num <= 19)
	{
		print_from_dict(num, couple_array);
	}
	else
		print_unit(num, couple_array);
}

void	print_hundreds(long long num, t_couple *couple_array)
{
	if (num >= 100)
	{
		print_unit(num / 100, couple_array);
		print_from_dict(100, couple_array);
		if (num % 100)
			print_tens(num % 100, couple_array);
	}
	else
		print_tens(num, couple_array);
}

void	print_number(long long num, t_couple *couple_array)
{
	if (num >= 1000000000)
	{
		print_hundreds(num / 1000000000, couple_array);
		print_from_dict(1000000000, couple_array);
		if (num % 1000000000)
			print_number(num % 1000000000, couple_array);
	}
	else if (num >= 1000000)
	{
		print_hundreds(num / 1000000, couple_array);
		print_from_dict(1000000, couple_array);
		if (num % 1000000)
			print_number(num % 1000000, couple_array);
	}
	else if (num >= 1000)
	{
		print_hundreds(num / 1000, couple_array);
		print_from_dict(1000, couple_array);
		if (num % 1000)
			print_number(num % 1000, couple_array);
	}
	else
	{
		print_hundreds(num, couple_array);
	}
}
