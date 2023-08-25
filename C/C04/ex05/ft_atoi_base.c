/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:34:14 by amura             #+#    #+#             */
/*   Updated: 2023/08/24 21:12:42 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_place(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_loop(char *str, char *base, int signe, int r)
{
	int	base_length;

	base_length = 0;
	while (base[base_length])
		base_length++;
	if (*str == '-' && r == 0)
		return (ft_atoi_loop(str + 1, base, signe *= -1, r));
	if (((*str >= 9 && *str <= 13) || *str == ' ' || *str == '+') && r == 0)
		return (ft_atoi_loop(str + 1, base, signe, r));
	if (get_place(*str, base) != -1)
	{
		r *= base_length;
		return (ft_atoi_loop(str + 1, base, signe, r + get_place(*str, base)));
	}
	return (r * signe);
}

int	ft_atoi_base(char *str, char *base)
{
	return (ft_atoi_loop(str, base, 1, 0));
}
