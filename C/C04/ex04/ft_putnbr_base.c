/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:39:47 by amura             #+#    #+#             */
/*   Updated: 2023/08/17 11:33:43 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr_base_loop(int nbr, char *base, int base_length)
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
				|| base[i] == '+' || base[i] == '-')
				return (0);
	}
	if (base_length <= 1)
		return (0);
	return (base_length);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_length;

	base_length = is_valid(base);
	if (!base_length)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	ft_putnbr_base_loop(nbr, base, base_length);
}
