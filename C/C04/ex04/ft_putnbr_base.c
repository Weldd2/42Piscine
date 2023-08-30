/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:39:47 by amura             #+#    #+#             */
/*   Updated: 2023/08/30 11:30:47 by amura            ###   ########.fr       */
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

int	is_valid(char *base, int *bl)
{
	int	str_l;
	int	i;
	int	j;

	str_l = 0;
	while (base[str_l])
		str_l++;
	*bl = str_l;
	if (str_l == 0 || str_l == 1)
		return (0);
	i = -1;
	while (base[++i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		j = i;
		while (base[++j])
			if (base[i] == base[j])
				return (0);
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_length;
	long	temp;

	temp = (long)nbr;
	if (!is_valid(base, &base_length))
		return ;
	if (!base_length)
		return ;
	if (temp < 0)
	{
		write(1, "-", 1);
		temp *= -1;
	}
	ft_putnbr_base_loop(temp, base, base_length);
}
