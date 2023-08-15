/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 09:38:18 by amura             #+#    #+#             */
/*   Updated: 2023/08/15 17:30:34 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	compteur;
	int	temp;
	int	fin;

	compteur = 0;
	temp = -1;
	fin = size - 1;
	while (compteur < fin)
	{
		temp = tab[compteur];
		tab[compteur] = tab[fin];
		tab[fin] = temp;
		compteur++;
		fin--;
	}
}
