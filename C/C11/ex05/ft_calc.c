/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:39:37 by amura             #+#    #+#             */
/*   Updated: 2023/08/31 22:22:20 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printnbr(long a);

void	addition(long a, long b)
{
	ft_printnbr(a + b);
	write(1, "\n", 1);
}

void	multiplication(long a, long b)
{
	ft_printnbr(a * b);
	write(1, "\n", 1);
}

void	soustraction(long a, long b)
{
	ft_printnbr(a - b);
	write(1, "\n", 1);
}

void	division(long a, long b)
{
	if (b == 0)
	{
		write(1, "Stop : division by zero\n", 25);
		return ;
	}
	ft_printnbr(a / b);
	write(1, "\n", 1);
}

void	modulo(long a, long b)
{
	if (b == 0)
	{
		write(1, "Stop : modulo by zero\n", 23);
		return ;
	}
	ft_printnbr(a % b);
	write(1, "\n", 1);
}
