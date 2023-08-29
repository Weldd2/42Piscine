/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:43:24 by amura             #+#    #+#             */
/*   Updated: 2023/08/29 15:00:00 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
		return (NULL);
	tab = malloc(sizeof(int) * (max - min));
	if (!tab)
		return (0);
	i = -1;
	while (min < max)
		tab[++i] = min++;
	return (tab);
}

#include <stdio.h>
int	main(void)
{
	int	*s = ft_range(5, 4);
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", s[i]);
		
	}
}