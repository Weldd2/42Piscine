/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:05:51 by amura             #+#    #+#             */
/*   Updated: 2023/08/17 19:30:16 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char const *argv[])
{
	int	i;
	int	j;

	i = 1;
	argc = (long)argc;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			write(STDOUT_FILENO, &argv[i][j], 1);
			j++;
		}
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
