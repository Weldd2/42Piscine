/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:34:14 by amura             #+#    #+#             */
/*   Updated: 2023/08/30 14:19:29 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_place(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (base[i] == c)
			return (i);
	return (-1);
}
int	get_error(char *nbr, char *base)
{
	int	i;
	
	i = -1;
	while (nbr[++i])
		if (get_place(nbr[i], base) == -1)
			return (-1);
}

int	is_valid(char *base, int *bl)
{
	int	str_l;
	int	i;
	int	j;

	str_l = 0;
	while (base[str_l])
		str_l++;
	*bl = str_l;
	if (str_l == 0 || str_l == 1)
		return (0);
	i = -1;
	while (base[++i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		j = i;
		while (base[++j])
			if (base[i] == base[j])
				return (0);
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	r;
	int	signe;
	int	base_l;

	if (!is_valid(base, &base_l))
		return (0);
	if (get_error(str, base))
		return (0);
	r = 0;
	signe = 1;
	while (*str == ' ' || (*str >= 7 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signe = -signe;
		str++;
	}
	while (*str <= '9' && *str >= '0')
	{
		r *= base_l;
		r += get_place(*str, base);
		str++;
	}
	return (r * signe);
}
