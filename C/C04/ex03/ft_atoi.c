/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:43:33 by amura             #+#    #+#             */
/*   Updated: 2023/08/17 09:55:47 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	power(long base, int l, int j)
{
	int	i;
	int	resultat;

	i = 0;
	resultat = 1;
	while (i < l - j - 1)
	{
		resultat *= base;
		i++;
	}
	return (resultat);
}

int	parse_number(char *str, int s, int p, int i, int l, int c)
{
	if (i < l)
	{
		if (!c)
		{
			if (str[i] == ' ')
				return (parse_number(str, s, p, i + 1, l, c));
			if (str[i] == '-')
				return (parse_number(str, s, p * -1, i + 1, l, c));
			if (str[i] <= '9' && str[i] >= '0')
				return (parse_number(str, ((str[i] - '0') * power(10, l, i)) + s, p, i + 1, l, 1));
		}
		else if (str[i] <= '9' && str[i] >= '0')
			return (parse_number(str, ((str[i] - '0') * power(10, l, i)) + s, p, i + 1, l, 1));
	}
	return (s * p);
}

int	ft_atoi(char *str)
{
	unsigned int	l;

	l = 0;
	while (str[l] == ' ' || str[l] == '-' || str[l] == '+')
		l++;
	while ((str[l] <= '9' && str[l] >= '0'))
		l++;
	return (parse_number(str, 0, 1, 0, l, 0));
}

int	main(void)
{
	char	*str;

	str = "123456";
	printf("test de : %s, resultat : %d\n", str, ft_atoi(str));

	str = "   123456";
	printf("test de : %s, resultat : %d\n", str, ft_atoi(str));

	str = "   -123456";
	printf("test de : %s, resultat : %d\n", str, ft_atoi(str));

	str = "   --123456";
	printf("test de : %s, resultat : %d\n", str, ft_atoi(str));

	str = "   --1234+56dasd";
	printf("test de : %s, resultat : %d\n", str, ft_atoi(str));
}
// parse_number(char *str, int somme, int positif, int compteur, int str_length, int chiffre)
