/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:34:14 by amura             #+#    #+#             */
/*   Updated: 2023/08/17 16:53:21 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_place(char c, char *base)
{
	int	i;

	i = 0;
	while(base[i])
	{
		if(base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_loop(char *str, char* base, int signe, int resultat)
{
	int	base_length;

	base_length = 0;
	while (base[base_length])
		base_length++;

	if(*str == '-' && resultat == 0)
		return (ft_atoi_loop(str + 1, base, signe *= -1, resultat));
	if(((*str >= 9 && *str <= 13) || *str == ' ' || *str == '+') && resultat == 0)
		return (ft_atoi_loop(str + 1, base, signe, resultat));
	if(get_place(*str, base) != -1)
	{
		resultat *= base_length;
		return (ft_atoi_loop(str + 1, base, signe, resultat + get_place(*str, base)));
	}
	return (resultat * signe);
}

int	ft_atoi_base(char *str, char *base)
{
	return (ft_atoi_loop(str, base, 1, 0));
}
