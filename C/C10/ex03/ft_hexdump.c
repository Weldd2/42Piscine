/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:54:27 by amura             #+#    #+#             */
/*   Updated: 2023/08/23 20:36:20 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <libgen.h>

char	*ft_strcat(char *dest, char *src)
{
	int				i;
	unsigned int	dest_length;

	i = 0;
	dest_length = 0;
	while (dest[dest_length])
		dest_length++;
	while (src[i] != '\0')
	{
		dest[i + dest_length] = src[i];
		i++;
	}
	dest[i + dest_length] = '\0';
	return (dest);
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

void	ft_print_hexa(char *str, int bytes_read)
{
	int	i;

	i = -1;
	while (str[++i] && i < bytes_read)
	{
		ft_convert_base(str[i], "0123456789abcdef", 16, str[i]);
		write(1, " ", 1);
		if (i == 7)
			write(1, " ", 1);
	}
	if (bytes_read != 16)
		print_x_space(((16 - bytes_read) * 3));
	if (bytes_read < 8)
		print_x_space(1);
	write(1, " |", 2);
}

char	*ft_replace_space_char(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= 7 && str[i] <= 13)
			str[i] = '.';
	}
	return (str);
}

void	ft_read_file(char *file_name)
{
	int		file;
	char	buffer[16];
	int		compteur;
	int		bytes_read;

	compteur = 0;
	file = open(file_name, O_RDONLY);
	while (1)
	{
		bytes_read = read(file, buffer, sizeof(buffer));
		print_offset(compteur);
		if (bytes_read <= 0)
		{
			write(1, "\n", 1);
			break ;
		}
		print_x_space(2);
		ft_print_hexa(buffer, bytes_read);
		ft_replace_space_char(buffer);
		write(1, buffer, bytes_read);
		write(1, "|\n", 2);
		ft_memset(buffer, 0, sizeof(buffer));
		compteur += bytes_read;
	}
	close(file);
}

int	get_option(char **argv, char char_to_detect, int *index)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (argv[i][0] == '-' && argv[i][1] == char_to_detect)
		{
			*index = i;
			return (1);
		}
	}
	return (0);
}

int	get_total_size(char **argv, int argc, int opt_index)
{
	int	i;
	int	str_len;

	i = 0;
	while (argc > ++i)
	{
		if (i == opt_index)
			continue ;
		str_len = -1;
		while (argv[i][++str_len]);
	}
	return (str_len);
}

void	parse_arguments(char **argv, int argc, int opt_index)
{
	int	i;
	int	str_len;
	char	*str;

	i = 0;
	str_len = 0;
	str_len = get_total_size(argv, argc, opt_index);
	str = malloc(sizeof(char) * str_len);
	if (!str)
		return ;
	while (argc > ++i)
	{
		if (i == opt_index)
			continue ;
		ft_strcat(str, argv[i]);
	}
	ft_read_file(str);
}

int	main(int argc, char **argv)
{
	int	opt_index;

	opt_index = 0;
	if (get_option(argv, 'C', &opt_index))
		parse_arguments(argv, argc, opt_index);
	else
		return (0);
	return (1);
}

//TODO actuellemt, concatene les noms des fichiers. Il faut concatener le contenu. Bon courage, je crois en toi