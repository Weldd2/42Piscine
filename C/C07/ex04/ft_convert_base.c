/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:40:16 by amura             #+#    #+#             */
/*   Updated: 2023/08/29 20:50:33 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	atoi_base(char *str, char *base, int s, int r);

char	*itoa_base(int nb, char *base, char *r, int i)
{
	int		base_l;
	int		j;
	char	*str2;

	base_l = -1;
	while (base[++base_l])
		;
	r[i] = base[nb % base_l];
	if (nb >= base_l)
	{
		return (itoa_base(nb / base_l, base, r, i + 1));
	}
	str2 = malloc(i * sizeof(char));
	j = 0;
	while (r[i])
		str2[j++] = r[i--];
	return (str2);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = -1;
	while (base[++i])
		;
	if (i < 2)
		return (0);
	i = 0;
	while (base[i + 1])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-'
				|| base[j] == '+' || base[j] == '-' || base[i] <= ' '
				|| base[i] > 126 || base[j] <= ' ' || base[j] > 126)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*inverse_number(char *str)
{
	char	*ns;
	int		str_l;
	int		i;

	str_l = -1;
	while (str[++str_l])
		;
	ns = malloc(str_l + 2);
	if (!ns)
		return (NULL);
	ns[0] = '-';
	i = -1;
	while (str[++i])
		ns[i + 1] = str[i];
	free(str);
	return (ns);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			nb;
	int			base_l;
	char		*str;
	int			signe;

	if (!(is_valid_base(base_from) && is_valid_base(base_to)))
		return (NULL);
	nb = atoi_base(nbr, base_from, 1, 0);
	signe = nb < 0;
	if (signe)
		nb *= -1;
	base_l = -1;
	while (base_to[++base_l])
		;
	str = malloc((nb / base_l) + 1);
	str = itoa_base(nb, base_to, str, 0);
	if (signe)
		str = inverse_number(str);
	return (str);
}
