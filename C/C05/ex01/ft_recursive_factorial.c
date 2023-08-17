/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:06:26 by amura             #+#    #+#             */
/*   Updated: 2023/08/17 17:10:39 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int ft_iterative_factorial(int nb)
{
	if (nb > 1)
		return (nb * ft_iterative_factorial((nb -1)));
	return nb;
}

#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_iterative_factorial(5));
}