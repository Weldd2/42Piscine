/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:34:14 by amura             #+#    #+#             */
/*   Updated: 2023/08/17 12:53:51 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi_2(char *str)
{
	int	r;
	int	signe;
	int	chiffre;

	signe = 1;
	chiffre = 0;
	r = 0;
	while (*str)
	{
		r *= 10;
		if (*str == ' ' && !chiffre) {}
		if (*str == '-' && !chiffre)
			signe *= -1;
		else if (*str <= '9' && *str >= '0')
		{
			chiffre = 1;
			r += (*str - '0');
		} else break;
		str++;
	}
	return (r * signe);
}

int	ft_atoi_base(char *str, char *base)
{
	base = (void*) base;
	return (ft_atoi_2(str));
}

#include <stdio.h>
int	main(void)
{
	printf("%d", ft_atoi_base("-450", "s"));
	
}