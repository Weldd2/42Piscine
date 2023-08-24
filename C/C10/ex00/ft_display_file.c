/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:45:27 by amura             #+#    #+#             */
/*   Updated: 2023/08/24 18:32:34 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(STDERR_FILENO, &str[i], 1);
		i++;
	}
}

int	ft_print_file_content(char *file_path)
{
	int		fichier;
	int		compteur;
	char	buffer[128];

	compteur = 0;
	fichier = open(file_path, O_RDONLY);
	if (fichier < 0)
		return (0);
	while (1)
	{
		compteur = read(fichier, buffer, sizeof(buffer));
		write(1, buffer, compteur);
		if (compteur < 128)
			break ;
	}
	close(fichier);
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		ft_putstr("File name missing.\n");
	else if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else if (!ft_print_file_content(argv[1]))
		ft_putstr("Cannot read file.\n");
	return (0);
}
