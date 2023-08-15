/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:44:50 by amura             #+#    #+#             */
/*   Updated: 2023/08/15 16:57:07 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	src_length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	j;
	
	while (*str)
	{
		j = 0;
		while (str[j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
			{
				return str;
			}	
			j++;
		}
		str++;
	}
	return 0;
}
