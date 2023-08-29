/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:14:33 by amura             #+#    #+#             */
/*   Updated: 2023/08/29 21:18:31 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_map(int *tab, int length, int(*f)(int))
{
	int	i;
	int	*r;
	
	i = -1;
	r = malloc(length * sizeof(int));
	while (++i < length)
		r[i] = f(tab[i]);
	return (r);
}
