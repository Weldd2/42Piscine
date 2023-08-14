/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 09:58:25 by amura             #+#    #+#             */
/*   Updated: 2023/08/14 17:17:03 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	compteur;
	int	temp;

	compteur = 0;
	temp = -1;
	while (compteur < (size - 1) && (tab[compteur]))
	{
		while (tab[compteur] > tab[compteur + 1])
		{
			temp = tab[compteur];
			tab[compteur] = tab[compteur + 1];
			tab[compteur + 1] = temp;
			compteur = 0;
		}
		compteur++;
	}
}
