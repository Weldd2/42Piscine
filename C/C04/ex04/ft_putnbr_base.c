/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:39:47 by amura             #+#    #+#             */
/*   Updated: 2023/08/25 12:52:38 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base_loop(long nbr, char *base, int base_length)
{
	if (nbr < base_length)
		write(1, &base[nbr], 1);
	else
	{
		ft_putnbr_base_loop(nbr / base_length, base, base_length);
		write(1, &base[nbr % base_length], 1);
	}
}

int	is_valid(char *base)
{
	int	base_length;
	int	i;

	base_length = -1;
	while (base[++base_length])
	{
		i = base_length;
		while (base[i++])
			if (base[i] == base[base_length] 
				|| base[i] == '+' || base[i] == '-' || base[i] == ' ')
				return (0);
	}
	if (base_length <= 1)
		return (0);
	return (base_length);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_length;
	long	temp;

	temp = (long)nbr;
	base_length = is_valid(base);
	if (!base_length)
		return ;
	if (temp < 0)
	{
		write(1, "-", 1);
		temp *= -1;
	}
	ft_putnbr_base_loop(temp, base, base_length);
}
