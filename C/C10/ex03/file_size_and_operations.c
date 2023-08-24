/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_size_and_operations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:25:40 by amura             #+#    #+#             */
/*   Updated: 2023/08/24 16:35:18 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_size_and_operations.h"

int	get_file_size(char *file_name, int	*error)
{
	int		file;
	int		size;
	char	buffer[16];

	size = 0;
	file = open(file_name, O_RDONLY);
	if (file < 0)
	{
		*error = 1;
		return (0);
	}
	while (read(file, buffer, sizeof(buffer)) > 0)
		size += sizeof(buffer);
	close(file);
	return (size);
}

int	get_total_size(char **argv, int argc, int opt_index)
{
	int	i;
	int	total_size;
	int	error;
	int	success;

	error = 0;
	success = 0;
	i = 0;
	total_size = 0;
	while (argc > ++i)
	{
		if (i == opt_index)
			continue ;
		total_size += get_file_size(argv[i], &error);
		if (error)
			ft_print_error(argv[i]);
		else
			success = 1;
	}
	if (!success)
		ft_print_full_error();
	return (total_size);
}

int	fill_tab_loop_end(int bytes_read, int i, int *file)
{
	if (bytes_read < 16)
	{
		i++;
		close(*file);
		*file = -1;
	}
	return (i);
}

char	*fill_tab(int argc, char **argv, char *tab)
{
	int		i;
	int		file;
	int		bytes_read;
	char	buffer[16];

	bytes_read = 0;
	file = -1;
	i = 2;
	while (1)
	{
		if (i == argc)
			break ;
		if (file == -1)
			file = open(argv[i], O_RDONLY);
		if (file < 0)
		{
			i++;
			continue ;
		}
		bytes_read = read(file, buffer, sizeof(buffer));
		ft_strncat(tab, buffer, sizeof(buffer));
		ft_memset(buffer, 0, sizeof(buffer));
		i = fill_tab_loop_end(bytes_read, i, &file);
	}
	return (tab);
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
