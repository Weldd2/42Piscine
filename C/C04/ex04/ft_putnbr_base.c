/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 02:46:37 by amura             #+#    #+#             */
/*   Updated: 2023/08/31 19:18:06 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 7 && base[i] <= 13))
			return (0);
		j = i;
		while (base[++j])
		{
			if (base[i] == base[j])
				return (0);
		}
	}
	return (1);
}

void	itoa_base_loop(long nb, char *base, int base_length)
{
	char	i;
	
	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	if (nb >= base_length)
		itoa_base_loop(nb / base_length, base, base_length);
	i = (base[nb % base_length]);
	write(1, &i, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;
	int		base_to_l;

	if (!is_valid(base, &base_to_l))
		return ;
	nb = (long)nbr;
	itoa_base_loop(nb, base, base_to_l);
}
