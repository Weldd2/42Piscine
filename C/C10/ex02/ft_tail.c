/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:45:27 by amura             #+#    #+#             */
/*   Updated: 2023/08/23 15:46:35 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"
#include "ft_funcs.h"

void	print_x_last_bytes(int file, int file_size, int bytes_read)
{
	char	buffer[1];
	int		f_cursor;

	if (bytes_read > file_size)
		bytes_read = file_size;
	f_cursor = 0;
	while (f_cursor < file_size - bytes_read)
	{
		if (read(file, buffer, 1) <= 0)
			return ;
		f_cursor++;
	}
	while (f_cursor < file_size)
	{
		if (read(file, buffer, 1) <= 0)
			return ;
		write(1, buffer, 1);
		f_cursor++;
	}
}

void	print_eof(char *file_name, int bytes_reads)
{
	int	file;
	int	file_size;

	file_size = 0;
	file = open(file_name, O_RDONLY);
	if (!file)
		return ;
	file_size = get_file_size(file);
	close(file);
	file = open(file_name, O_RDONLY);
	print_x_last_bytes(file, file_size, bytes_reads);
	close(file);
}

int	tail_loop(char **argv, int argc, int opt_index, int bytes_read)
{
	int	i;

	i = 0;
	while (argc > ++i)
	{
		if (i == opt_index || i == opt_index + 1)
			continue ;
		if (argc > 4)
		{
			ft_putstr("==>", 1);
			ft_putstr(argv[i], 1);
			ft_putstr("<==\n", 1);
		}
		print_eof(argv[i], bytes_read);
		if ((i != argc && argc > 4))
			ft_putstr("\n", 1);
	}
}

int	main(int argc, char *argv[])
{
	int	bytes_read;	
	int	opt_index;

	bytes_read = 0;
	opt_index = 0;
	bytes_read = get_option(argv, 'c', argc, &opt_index);
	if (bytes_read > 0)
	{
		tail_loop(argv, argc, opt_index, bytes_read);
	}
	return (0);
}
