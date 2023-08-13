/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:08:31 by amura             #+#    #+#             */
/*   Updated: 2023/08/13 14:53:48 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_lowercase(char c)
{
	if (c > 'z' || c < 'a')
	{
		return (0);
	}
	return (1);
}

int	is_numeric(char c)
{
	if (c > '9' || c < '0')
	{
		return (0);
	}
	return (1);
}

int	is_alpha(char c)
{
	if ( (c <	 'A' || c > 'Z') && (c < 'a' || c > 'z'))
	{
		return (0);
	}
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	cap;

	i = 0;
	cap = 0;
	while (str[i])
	{
		if (is_numeric(str[i]) || is_alpha(str[i]))
		{
			if (cap && is_alpha(str[i]) && is_lowercase(str[i]))
			{
				str[i] += 32;
			}
		}
		else
		{
			cap = 1;
		}
		i++;
	}
	return (str);
}

int	main(void)
{
	char str[35] = "Pas de soucis pour moi"; 
	
	ft_strcapitalize(str);
	printf("%s", str);
}
