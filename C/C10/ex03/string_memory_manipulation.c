/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_memory_manipulation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:26:46 by amura             #+#    #+#             */
/*   Updated: 2023/08/24 16:34:12 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_memory_manipulation.h"

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	l;

	i = -1;
	l = 0;
	while (dest[++i])
		l++;
	i = 0;
	while (src[i] != '\0' && i < nb)
	{
		dest[i + l] = src[i];
		i++;
	}
	dest[i + l] = '\0';
	return (dest);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)b;
	i = -1;
	while (++i < len)
		ptr[i] = (unsigned char)c;
	return (b);
}

void	print_offset(int place)
{
	int		i;
	int		tmp;

	tmp = place;
	if (place == 0)
		i = 0;
	else
		i = -1;
	while (tmp > 0)
	{
		tmp /= 16;
		i++;
	}
	while (i < 7)
	{
		write(1, "0", 1);
		i++;
	}
	ft_convert_base(place, "0123456789abcdef", 16, 17);
	print_x_space(2);
}

void	print_ascii(char *tab, int place)
{
	int	i;
	int	stop;

	i = place;
	stop = i + 16;
	write(1, " |", 2);
	while (i < stop && tab[i])
	{
		write(1, &tab[i], 1);
		i++;
	}
	write(1, "|\n", 2);
}

void	print_hexa(char *tab, int place, int tab_length)
{
	int	i;
	int	stop;

	i = place;
	stop = i + 16;
	while (i < stop && tab[i])
	{
		ft_convert_base(tab[i], "0123456789abcdef", 16, tab[i]);
		if (i == stop - 8)
			print_x_space(1);
		print_x_space(1);
		i++;
	}
	if (tab_length - i == 0)
		print_x_space((16 - (tab_length - place)) * 3 + (tab_length - i < 7));
}
