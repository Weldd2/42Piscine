/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:34:14 by amura             #+#    #+#             */
/*   Updated: 2023/08/25 12:47:03 by amura            ###   ########.fr       */
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

int	is_valid(char *base)
{
	int	base_length;
	int	i;

	base_length = -1;
	while (base[++base_length])
	{
		i = base_length;
		while (base[i++])
			if (base[i] == base[base_length] 
				|| base[i] == '+' || base[i] == '-' || base[i] == ' ')
				return (0);
	}
	if (base_length <= 1)
		return (0);
	return (base_length);
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
	if (is_valid(base))
		return (ft_atoi_loop(str, base, 1, 0));
	return (0);
}
