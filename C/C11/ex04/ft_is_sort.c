/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:32:54 by amura             #+#    #+#             */
/*   Updated: 2023/08/29 21:44:32 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	s;

	if (length == 0 || length == 1)
		return (1);
	s = f(tab[0], tab[1]);
	i = -1;
	while (++i < length && i + 1 < length)
	{
		if (f(tab[i], tab[i + 1]) == s || f(tab[i], tab[i + 1]) == 0)
			continue ;
		else
			return (0);
	}
	return (1);
}

#include <stdlib.h>
#include <unistd.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int));

int	compare(int a, int b)
{
	if (a > b)
		return (1);
	else if (a < b)
		return (-1);
	else
		return (0);
}

void	print_result(int result)
{
	if (result)
		write(1, "1\n", 2);
	else
		write(1, "0\n", 2);
}

int	main(void)
{
	int	*tab;
	int	result;

	tab = malloc(5 * sizeof(int));
	if (!tab)
		return (1);
	tab[0] = 5;
	tab[1] = 5;
	tab[2] = 3;
	tab[3] = 2;
	tab[4] = 1;

	result = ft_is_sort(tab, 5, compare);
	print_result(result);

	free(tab);
	return (0);
}
