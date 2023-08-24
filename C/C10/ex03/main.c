/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:35:44 by amura             #+#    #+#             */
/*   Updated: 2023/08/24 16:33:11 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "output.h"

void	parse_tab(char *tab)
{
	int	i;
	int	tab_length;

	i = 0;
	tab_length = 0;
	while (tab[tab_length])
		tab_length++;
	while (tab[i])
	{
		print_offset(i);
		print_hexa(tab, i, tab_length);
		print_ascii(tab, i);
		i += 16;
	}
	print_offset(tab_length);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	char	*tab;
	int		full_size;
	int		opt_index;

	opt_index = 0;
	if (!get_option(argv, 'C', &opt_index))
		return (0);
	full_size = 0;
	full_size = get_total_size(argv, argc, opt_index);
	tab = malloc(full_size * sizeof(char));
	if (!tab || full_size == 0)
		return (0);
	fill_tab(argc, argv, tab);
	parse_tab(tab);
	return (0);
}
