/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:09:06 by amura             #+#    #+#             */
/*   Updated: 2023/08/17 19:30:39 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(STDOUT_FILENO, &str[i], 1);
		i++;
	}
}

int	main(int argc, char const *argv[])
{
	int	i;

	i = argc - 1; 
	while (i > 0) 
	{
		print(argv[i]);
		print("\n");
		i--;
	}
	return (0);
}
