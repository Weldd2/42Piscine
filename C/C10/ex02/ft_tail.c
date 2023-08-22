/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:45:27 by amura             #+#    #+#             */
/*   Updated: 2023/08/22 20:49:33 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void	ft_putstr(const char *str, int sortie)
{
	while (*str)
		write(sortie, str++, 1);
}

void	ft_print_error(char *file_path)
{
	ft_putstr("ft_cat: ", STDERR_FILENO);
	ft_putstr(file_path, STDERR_FILENO);
	ft_putstr(": ", STDERR_FILENO);
	ft_putstr(strerror(errno), STDERR_FILENO);
	ft_putstr("\n", STDERR_FILENO);
}

int	get_file_size(char *file_path)
{
	char *buffer;
	int	file_size;
	int	compteur;
	int	file;
	
	file_size = 0;
	buffer = malloc(sizeof(char));
	file = open(file_path, O_RDONLY);
	if (file < 0)
		ft_print_error(file_path);
	while((compteur = read(file, buffer, sizeof(char))) > 0)
		file_size += compteur;
	free(buffer);
	close(file);
	return (file_size);
}

int	ft_print_eof_content(char **file_path, int argc,  int bytes_read, int arg_index)
{
	char buffer[1];
	int	file_size;
	int	file_cursor;
	int	i;
	int	file;
	int	compteur;

	i = 0;
	file_cursor = 0;
	compteur = 0;
	file_size = 0;
	while(++i < argc)
	{
		if (i != arg_index && i != arg_index + 1)
		{
			file_size = get_file_size(file_path[i]);
			file = open(file_path[i], O_RDONLY);
			if (file < 0)
				ft_print_error(file_path[i]);
			while((compteur = read(file, buffer, 1)) > 0)
			{
				file_cursor += compteur;
				if ((file_cursor > file_size - bytes_read) && (file_cursor < file_size + 1))
					write(1, buffer, 1);
			}
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

int	get_option(char **argv, char char_to_detect, int argc,int *arg_index)
{
	int	i;
	int	str_len;
	int	r;

	i = -1;
	while(argv[++i])
	{
		str_len = 0;
		while(argv[i][str_len])
			str_len++;
		if (str_len == 2 && (argv[i][0] == '-' && argv[i][1] == char_to_detect) && (argc > i + 1))
		{
			r = ft_get_nbr(argv[i + 1], 0);
			if(r > 0)
			{
				*arg_index = i;
				return (r);
			}
		}
	}
	return (0);
}

int main(int argc, char *argv[])
{
	int	arg_index;
	int	bytes_read;

	bytes_read = 0;
	arg_index = 0;
	bytes_read = get_option(argv, 'c',argc, &arg_index);
	if (bytes_read > 0)
		ft_print_eof_content(argv, argc, bytes_read, arg_index);
	return (0);
}