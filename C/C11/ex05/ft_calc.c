/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:39:37 by amura             #+#    #+#             */
/*   Updated: 2023/08/30 15:00:56 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printnbr(int a);

void	addition(int a, int b)
{
	ft_printnbr(a + b);
}

void	multiplication(int a, int b)
{
	ft_printnbr(a * b);
}

void	soustraction(int a, int b)
{
	ft_printnbr(a - b);
}

void	division(int a, int b)
{
	if (b == 0)
	{
		write(1, "Stop : division by zero", 24);
		return ;
	}
	ft_printnbr(a / b);
}

void	modulo(int a, int b)
{
	if (b == 0)
	{
		write(1, "Stop : modulo by zero", 22);
		return ;
	}
	ft_printnbr(a % b);
}
