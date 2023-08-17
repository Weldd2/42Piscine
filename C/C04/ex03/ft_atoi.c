/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:54:10 by amura             #+#    #+#             */
/*   Updated: 2023/08/17 12:54:32 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
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