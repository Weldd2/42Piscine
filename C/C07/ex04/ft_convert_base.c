/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 02:46:37 by amura             #+#    #+#             */
/*   Updated: 2023/08/30 02:47:42 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_params
{
	char	*str;
	long	nb;
	char	*base;
	int		base_len;
}	t_params;

int	ft_nbrlen(long nb, int base_len)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len = 1;
	while (nb != 0)
	{
		nb /= base_len;
		len++;
	}
	return (len);
}

void	fill_str(t_params *p, int len)
{
	long	tmp;

	while (p->nb != 0)
	{
		tmp = p->nb % p->base_len;
		if (tmp < 0)
			tmp = -tmp;
		p->str[len] = p->base[tmp];
		len--;
		p->nb /= p->base_len;
	}
}

char	*itoa_base(long nb, char *base, int base_len)
{
	char		*r;
	int			len;
	int			is_negative;
	t_params	p;

	is_negative = (nb < 0);
	len = ft_nbrlen(nb, base_len);
	r = malloc(len + 1);
	if (!r)
		return (NULL);
	r[len] = '\0';
	p = (t_params){r, nb, base, base_len};
	if (nb == 0)
		r[0] = base[0];
	else
		fill_str(&p, len - 1);
	if (is_negative)
		r[0] = '-';
	return (r);
}
