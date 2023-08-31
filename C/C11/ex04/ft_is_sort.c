/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:32:54 by amura             #+#    #+#             */
/*   Updated: 2023/08/31 22:10:11 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	s;

	if (length == 0 || length == 1)
		return (1);
	i = 1;
	s = 0;
	while (!s)
	{
		s = f(tab[i - 1], tab[i]);
		i++;
	}
	while (i < length)
	{
		if (f(tab[i - 1], tab[i]) == s || f(tab[i - 1], tab[i]) == 0)
			continue ;
		else
			return (0);
		i++;
	}
	return (1);
}
