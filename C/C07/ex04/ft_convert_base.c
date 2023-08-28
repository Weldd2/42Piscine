/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:40:16 by amura             #+#    #+#             */
/*   Updated: 2023/08/28 20:41:00 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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

char	*itoa_base(int nb, char *base, char *r, int i)
{
	int	base_l;
	int	j;
	char	*str2;

	base_l = -1;
	while(base[++base_l]);
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

// char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
// {
// 	long long	nb;

// 	if (!(is_valid(base_from) && is_valid(base_to)))
// 		return (NULL);
// 	nb = convert_from(nbr, base_from, 1);
// 	return (convert_to(nb, base_to));
// }

#include <stdio.h>
int	main(void)
{
	printf("%s\n", itoa_base(10, "01", malloc(65), 0));	
}