/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:26:48 by amura             #+#    #+#             */
/*   Updated: 2023/08/29 22:57:00 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		write(1, &str[i], 1);
	}
	write(1, "\n", 1); 
}

void	ft_putnbr(int nb)
{
	int	temp;

	temp = nb;
	temp += '0';
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
			return ;
		}
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		temp = nb % 10;
		nb = nb / 10;
		temp += '0';
		ft_putnbr(nb);
	}
	write(1, &temp, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putstr(par[i].copy);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		i++;
	}
}
