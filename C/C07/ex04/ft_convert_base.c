/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:40:16 by amura             #+#    #+#             */
/*   Updated: 2023/08/21 10:50:43 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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

long long	convert_from(char *nbr, char *bf, int p)
{
	int		bl;
	long long	r;

	r = 0;
	bl = 0;
	while (bf[bl])
		bl++;
	if (*nbr == '-' || ((*nbr >= 9 && *nbr <= 13) 
			|| *nbr == ' ' || *nbr == '+'))
	{
		if (*nbr == '-')
			p *= -1;
		return (convert_from(nbr + 1, bf, p));
	}
	while (*nbr && get_place(*nbr, bf) != -1)
	{
		r = r * bl + get_place(*nbr, bf);
		nbr++;
	}
	return (r * p);
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
				|| base[i] == '+' || base[i] == '-')
				return (0);
	}
	if (base_length <= 1)
		return (0);
	return (base_length);
}

char	*convert_to(int nb, char *base_to)
{
	int	i;
	int	bl;
	int	length;
	int	temp_nb;
	char	*result;

	bl = 0;
	while (base_to[bl])
		bl++;
	length = 1;
	temp_nb = nb;
	while (temp_nb >= bl)
	{
		length++;
		temp_nb /= bl;
	}
	result = malloc((length + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = length - 1;
	result[length] = '\0';
	while (nb >= bl)
	{
		result[i--] = base_to[nb % bl];
		nb /= bl;
	}
	result[i] = base_to[nb % bl];
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	nb;

	if (!(is_valid(base_from) && is_valid(base_to)))
		return (NULL);
	nb = convert_from(nbr, base_from, 1);
	return (convert_to(nb, base_to));
}
