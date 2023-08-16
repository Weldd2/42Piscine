/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:43:33 by amura             #+#    #+#             */
/*   Updated: 2023/08/16 12:12:15 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char*	parse_number(char *str, int compteur, int positif, int chiffre)
{
	if (*str != '\0')
	{	
		if (chiffre == 0)
		{
			if (*str == ' ')
				parse_number(str + 1, compteur + 1, positif, chiffre);
			if (*str == '+')
				parse_number(str + 1, compteur + 1, 1, chiffre);
			if (*str == '-')
			{
				if (positif == 0)
					parse_number(str + 1, compteur + 1, 1, chiffre);
				else
					parse_number(str + 1, compteur + 1, 0, chiffre);
			}
			if (*str > '0' || *str < '9')
			{

				write(1, &str, 1);
				parse_number(str + 1, compteur + 1, 0, 1);
			}
		}
		else
		{
			if (*str > '0' || *str < '9')
			{
				write(1, &str, 1);	
				parse_number(str + 1, compteur + 1, 0, 1);
			}
			else
				return "";
		}
	}
	return ("");
}

int	ft_atoi(char *str)
{
	parse_number(str, 0, 1, 0);
	return (0);
}

#include <stdio.h>
int	main(void)
{
	char *str;

	str = "1234";
	ft_atoi(str);
}