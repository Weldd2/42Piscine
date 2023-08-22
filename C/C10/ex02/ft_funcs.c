/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:28:07 by amura             #+#    #+#             */
/*   Updated: 2023/08/22 23:04:17 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_funcs.h"

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
	char	*buffer;
	int		file_size;
	int		compteur;
	int		file;

	file_size = 0;
	buffer = malloc(sizeof(char));
	file = open(file_path, O_RDONLY);
	compteur = 1;
	if (file < 0)
		ft_print_error(file_path);
	while (compteur > 0)
	{
		compteur = read(file, buffer, sizeof(char));
		file_size += compteur;
	}
	free(buffer);
	close(file);
	return (file_size);
}

void	print_file_sep_start(char *file_path)
{
	ft_putstr("==> ", STDOUT_FILENO);
	ft_putstr(basename(file_path), STDOUT_FILENO);
	ft_putstr(" <==\n", STDOUT_FILENO);
}
