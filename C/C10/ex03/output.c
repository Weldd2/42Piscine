/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:24:49 by amura             #+#    #+#             */
/*   Updated: 2023/08/24 16:29:54 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output.h"

void	ft_putstr(const char *str, int sortie)
{
	while (*str)
		write(sortie, str++, 1);
}

void	ft_print_error(char *file_path)
{
	ft_putstr("hexdump: ", STDERR_FILENO);
	ft_putstr(file_path, STDERR_FILENO);
	ft_putstr(": ", STDERR_FILENO);
	ft_putstr(strerror(errno), STDERR_FILENO);
	ft_putstr("\n", STDERR_FILENO);
}

void	ft_print_full_error(void)
{
	ft_putstr("hexdump: ", STDERR_FILENO);
	ft_putstr("all input file arguments failed\n", STDERR_FILENO);
}

void	print_x_space(int x)
{
	int	i;

	i = -1;
	while (++i < x)
		write(1, " ", 1);
}

void	ft_convert_base(int nb, char *base, int base_length, int start_value)
{
	if (nb >= base_length)
	{
		ft_convert_base(nb / base_length, base, base_length, start_value);
	}
	if (start_value < 16)
		write(1, "0", 1);
	write(1, &base[nb % base_length], 1);
}
