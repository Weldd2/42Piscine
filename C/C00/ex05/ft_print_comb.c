/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:16:15 by amura             #+#    #+#             */
/*   Updated: 2023/08/10 18:52:41 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_str(char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
		str++;
	}
}

void	print_result(int a, int b, int c)
{
	int	i;
	int	j;
	int	k;

	i = a + '0';
	j = b + '0';
	k = c + '0';
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
	if (a == 7 && b == 8 && c == 9)
	{
	}
	else
	{
		print_str(", ");
	}
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i <= 7)
	{
		j = i + 1;
		while (j <= 8)
		{
			k = j + 1;
			while (k <= 9)
			{
				print_result(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
