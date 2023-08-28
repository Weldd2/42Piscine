/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:43:24 by amura             #+#    #+#             */
/*   Updated: 2023/08/28 16:42:06 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	tab = malloc(sizeof(int) * (max - min));
	if (!tab)
		return (0);
	i = -1;
	while (min < max)
		tab[++i] = min++;
	return (tab);
}
