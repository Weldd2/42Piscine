/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:01:49 by amura             #+#    #+#             */
/*   Updated: 2023/08/14 12:23:48 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lowcase(char c)
{
	if (c > 'z' || c < 'a')
	{
		return (0);
	}
	return (1);
}

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_lowcase(str[i]))
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}
