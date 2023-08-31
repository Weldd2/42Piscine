/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:51:58 by amura             #+#    #+#             */
/*   Updated: 2023/08/31 22:38:22 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printnbr(long n)
{
	long	temp;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_printnbr(n / 10);
	temp = (n % 10 + '0');
	write(1, &temp, 1);
}

long	ft_atoi(char *str)
{
	long	r;
	long	signe;

	r = 0;
	signe = 1;
	while (*str == ' ' || (*str >= 7 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signe = -signe;
		str++;
	}
	while (*str <= '9' && *str >= '0')
	{
		r *= 10;
		r += (*str - '0');
		str++;
	}
	return (r * signe);
}
