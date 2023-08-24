/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:45:27 by amura             #+#    #+#             */
/*   Updated: 2023/08/24 18:30:11 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

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

int	ft_print_file_content(char **file_path, int size)
{
	int		fichier;
	int		compteur;
	int		i;
	char	buffer[128];

	i = 0;
	while (++i < size)
	{
		compteur = 0;
		fichier = open(file_path[i], O_RDONLY);
		if (fichier < 0)
			ft_print_error(file_path[i]);
		while (1)
		{
			compteur = read(fichier, buffer, sizeof(buffer));
			write(1, buffer, compteur);
			if (compteur < 128)
				break ;
		}
		close(fichier);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	ft_print_file_content(argv, argc);
	return (0);
}
