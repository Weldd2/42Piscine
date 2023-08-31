/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 02:46:37 by amura             #+#    #+#             */
/*   Updated: 2023/08/31 18:03:30 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_place(char c, char *base);
int	is_valid(char *base, int *bl);

long	atoi_base(char *nbr, char *base, int base_length)
{
	long	r;
	int		s;

	s = 1;
	r = 0;
	while (*nbr == ' ' || (*nbr >= 7 && *nbr <= 13))
		nbr++;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			s = -s;
		nbr++;
	}
	while (get_place(*nbr, base) != -1)
	{
		r *= base_length;
		r += get_place(*nbr, base);
		nbr++;
	}
	return (r * s);
}

int	get_nb_size(long nbr, int base_length)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= base_length;
		i++;
	}
	return (i);
}

void	itoa_base_loop(long nbr, char *base, int base_length, char *r)
{
	*r = base[nbr % base_length];
	if (nbr >= base_length)
		itoa_base_loop(nbr / base_length, base, base_length, r - 1);
}

char	*itoa_base(long nbr, char *base, int base_length)
{
	char	*r;
	int		nb_size;

	nb_size = get_nb_size(nbr, base_length);
	r = malloc(nb_size * sizeof(char));
	if (!r)
		return (NULL);
	if (nbr < 0)
	{
		*r = '-';
		nbr = -nbr;
	}
	itoa_base_loop(nbr, base, base_length, r + (nb_size - 1));
	return (r);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	nb;
	int		base_from_l;
	int		base_to_l;

	if (!(is_valid(base_from, &base_from_l) && is_valid(base_to, &base_to_l)))
		return (NULL);
	nb = atoi_base(nbr, base_from, base_from_l);
	return (itoa_base(nb, base_to, base_to_l));
}
