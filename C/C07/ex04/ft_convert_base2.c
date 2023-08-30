/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 00:22:03 by amura             #+#    #+#             */
/*   Updated: 2023/08/30 12:12:17 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*itoa_base(long nb, char *base, int b_l);

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
		{
			if (base[i] == base[j])
			{
				return (0);
			}
		}
	}
	return (1);
}

int	get_place(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (base[i] == c)
			return (i);
	return (0);
}

int	atoi_base(char *str, char *base, int base_l)
{
	int	r;
	int	signe;

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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		bf_l;
	int		bt_l;
	int		nb;
	char	*r;

	if (!(is_valid(base_from, &bf_l) && is_valid(base_to, &bt_l)))
		return (0);
	nb = atoi_base(nbr, base_from, bf_l);
	r = itoa_base(nb, base_to, bt_l);
	return (r);
}
