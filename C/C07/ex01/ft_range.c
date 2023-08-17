/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:43:24 by amura             #+#    #+#             */
/*   Updated: 2023/08/17 20:12:23 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;
	int	size;

	size = max - min - 2;
	if (size <= 0)
		return (NULL);
	tab = malloc(size * 4);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = min + 1;
		i++;
		min++;
	}
	return (tab);
}
