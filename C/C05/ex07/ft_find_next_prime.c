/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:07:28 by amura             #+#    #+#             */
/*   Updated: 2023/08/23 13:14:17 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	i = 5;
	while (i * i <= nb && i * i > 0)
	{
		if (nb % i == 0 || nb % (i + 2) == 0)
			return (0);
		i += 6;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	if (nb % 2 == 0 && nb != 2)
		nb++;
	while (1)
	{
		if (ft_is_prime(nb))
			return (nb);
		if (nb > 2147483647 - 2)
			break; // Empêcher le débordement d'entiers
		nb += 2;
	}
	return (-1); // Retourner -1 si aucun nombre premier n'est trouvé
}


#include <stdio.h>
int	main(void)
{
	printf("%d", ft_find_next_prime(2147483637));
}