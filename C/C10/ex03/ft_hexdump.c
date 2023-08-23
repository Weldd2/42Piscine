/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:54:27 by amura             #+#    #+#             */
/*   Updated: 2023/08/23 17:01:20 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <libgen.h>

void	ft_putstr(const char *str, int sortie)
{
	while (*str)
		write(sortie, str++, 1);
}

void	ft_convert_base(int nb, char *base, int base_length)
{
	if (nb >= base_length)
	{
		ft_convert_base(nb / base_length, base, base_length);
	}
	write(1, &base[nb % base_length], 1);
}

void	ft_print_chiffre(int i)
{
	write(1, &i, 1);
}

void	print_offset(int place)
{
	ft_convert_base(place, "0123456789abcdef", 16);
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

void	ft_read_file(char *file_name)
{
	int	file;
	char	buffer[16];
	int	compteur;
	int	i;

	compteur = 0;
	file = open(file_name, O_RDONLY);
	while (read(file, buffer, sizeof(buffer)) > 0)
	{
		i = -1;
		print_offset(compteur);
		ft_putstr("\t", 1);
		while (buffer[++i])
		{
			ft_convert_base(buffer[i], "0123456789abcdef", 16);
			write(1, " ", 1);
		}
		write(1, "|", 1);
		write(1, buffer, sizeof(buffer));
		write(1, "|\n", 2);
		ft_memset(buffer, 0, sizeof(buffer));
		compteur += 16;
	}
	close(file);
}

#include <stdio.h>
int	main(void)
{
	ft_read_file("fichier.txt");
}