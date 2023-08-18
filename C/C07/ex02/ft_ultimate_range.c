/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:50:40 by amura             #+#    #+#             */
/*   Updated: 2023/08/18 11:15:43 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	size = max - min;
	if (size <= 0)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(size * sizeof(int));
	if (!(*range))
		return (-1);
	i = 0;
	while (i < size)
	{
		(*range)[i] = min;
		i++;
		min++;
	}
	return (size);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int *strs[2];
// 	int s1[3] = {1, 2, 3};
// 	int s2[3] = {1, 2, 3};

// 	strs[0] = s1;
// 	strs[1] = s2;
// 	ft_ultimate_range(strs, 3, 5);
// }
