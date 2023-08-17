/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:03:15 by amura             #+#    #+#             */
/*   Updated: 2023/08/17 18:00:20 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int	n;
	int	temp;

	temp = nb;
	temp += '0';
	if (nb < 0)
	{
		n = '-';
		write(1, &n, 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		temp = nb % 10;
		temp += '0';
		nb = nb / 10;
		ft_putnbr(nb);
	}
	write(1, &temp, 1);
}

int	power(int expose, int exposant)
{
	int	i;
	int	temp;

	i = 1;
	temp = expose;
	while (i < exposant)
	{
		temp = temp * expose; 
		i++;
	}
	return (temp);
}

int	*ft_nb_slice(int nb, int iteration, int *r)
{
	int	temp;

	if (nb >= 10)
	{
		temp = nb % 10;
		nb = nb / 10;
		r[iteration] = temp;
		ft_nb_slice(nb, iteration + 1, r);
	}
	else 
	{
		r[iteration] = nb;
	}
	return (r);
}

void	tab_init(int *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		tab[i] = 0;
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	j;
	int	bool;
	int	tab[10];

	i = 0;
	while (i < power(10, n))
	{
		tab_init(tab);
		
		ft_nb_slice(i, 0, tab);
		j = n-1;
		bool = 1;
		while (j >= 0)
		{
			if (tab[j] <= tab[j+1])
				bool = 0;
			j--;
		}
		if (bool)
		{
			ft_putnbr(i);
			write(1, "\n", 1);
		}
		i++;
	}
}
