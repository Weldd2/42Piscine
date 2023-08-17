/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:57:25 by amura             #+#    #+#             */
/*   Updated: 2023/08/18 00:13:35 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

int	get_str_length(char *base)
{
	int	bl;

	bl = 0;
	while (base[bl])
		bl++;
	return (bl);
}

int	convert_from(char *nbr, char *bf, int p, int r)
{
	int	bl;

	bl = get_str_length(bf);
	if (*nbr == '-' && r == 0)
		return (convert_from(nbr + 1, bf, p *= -1, r));
	if (((*nbr >= 9 && *nbr <= 13) || *nbr == ' ' || *nbr == '+') && r == 0)
		return (convert_from(nbr + 1, bf, p, r));
	if (get_place(*nbr, bf) != -1)
	{
		r *= bl;
		return (convert_from(nbr + 1, bf, p, r + get_place(*nbr, bf)));
	}
	return (r * p);
}

char	*convert_to(int nb, char *base_to, char *r)
{
	int	bl;

	bl = get_str_length(base_to);
	if (nb >= bl)
		convert_to(nb / bl, base_to, r + 1);
	*r = base_to[nb % bl];
	return (r);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nb;
	char	*r;
	
	r = malloc(get_str_length(nbr) / get_str_length(base_to) + 1);
	nb = convert_from(nbr, base_from, 1, 0);
	return (convert_to(nb, base_to, r));
}

#include <stdio.h>
int	main(void)
{
	printf("%s", ft_convert_base("140", "0123456789", "0123456789abcdef"));
}