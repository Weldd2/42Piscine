/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:45:27 by amura             #+#    #+#             */
/*   Updated: 2023/08/22 23:02:09 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"
#include "ft_funcs.h"

void	print_x_last_bytes(int file, int file_size, int bytes_read)
{
	char	buffer[1];
	int		f_cursor;
	int		compteur;

	f_cursor = 0;
	compteur = 0;
	while ((compteur = read(file, buffer, 1)) > 0)
	{
		f_cursor += compteur;
		if ((f_cursor > file_size - bytes_read) && (f_cursor < file_size + 1))
			write(1, buffer, 1);
	}
}

int	ft_print_eof_c(char **file_path, int argc, int bytes_read, int arg_index)
{
	int	file_size;
	int	i;
	int	file;

	i = 0;
	file_size = 0;
	while (++i < argc)
	{
		if (i != arg_index && i != arg_index + 1)
		{
			print_file_sep_start(file_path[i]);
			file_size = get_file_size(file_path[i]);
			file = open(file_path[i], O_RDONLY);
			if (file < 0)
				ft_print_error(file_path[i]);
			print_x_last_bytes(file, file_size, bytes_read);
		}
	}
	return (1);
}

int	ft_get_nbr(char *str, int result)
{
	if (*str <= '9' && *str >= '0')
		return (ft_get_nbr(str + 1, (result * 10) + (*str - '0')));
	return (result);
}

int	get_option(char **argv, char char_to_detect, int argc, int *arg_i)
{
	int	i;
	int	str_len;
	int	r;

	i = -1;
	while (argv[++i])
	{
		str_len = 0;
		while (argv[i][str_len])
			str_len++;
		if (str_len == 2 && (argv[i][0] == '-' && argv[i][1] == char_to_detect)
			&& (argc > i + 1))
		{
			r = ft_get_nbr(argv[i + 1], 0);
			if (r > 0)
			{
				*arg_i = i;
				return (r);
			}
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	arg_index;
	int	bytes_read;

	bytes_read = 0;
	arg_index = 0;
	bytes_read = get_option(argv, 'c', argc, &arg_index);
	if (bytes_read > 0)
		ft_print_eof_c(argv, argc, bytes_read, arg_index);
	return (0);
}
