/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:43:33 by amura             #+#    #+#             */
/*   Updated: 2023/08/17 09:44:22 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

long long	power (long base, int exposant)
{
	int	i;
	long long	resultat;

	i = 0;
	resultat = 1;
	while (i < exposant)
	{
		resultat *= base;
		i++;
	}
	return (resultat);
}

int c_t_i(char c)
{
	return (c - '0');
}

int	parse_number(char *str, int somme, int positif, int compteur, int str_length, int chiffre)
{
	if(compteur < str_length)
	{
		if (!chiffre)
		{
			if (str[compteur] == ' ')
				return (parse_number(str, somme, positif, compteur + 1, str_length, chiffre));
			if (str[compteur] == '-')
				return (parse_number(str, somme, positif * -1, compteur + 1, str_length, chiffre));
			if (str[compteur] <= '9' && str[compteur] >= '0')
				return (parse_number(str, (c_t_i(str[compteur]) * power(10, str_length - compteur - 1)) + somme, positif, compteur + 1, str_length, 1));
		}
		else if (str[compteur] <= '9' && str[compteur] >= '0')
			return (parse_number(str, (c_t_i(str[compteur]) * power(10, str_length - compteur - 1)) + somme, positif, compteur + 1, str_length, 1));
	}
	return somme * positif;
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
	char *str;

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
