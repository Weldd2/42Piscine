/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:30:42 by amura             #+#    #+#             */
/*   Updated: 2023/08/14 11:30:47 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_uppercase(char c)
{
	if (c > 'Z' || c < 'A')
	{
		return (0);
	}
	return (1);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_uppercase(str[i]))
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}
