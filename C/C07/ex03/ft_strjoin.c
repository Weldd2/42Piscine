/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:10:12 by amura             #+#    #+#             */
/*   Updated: 2023/08/17 22:56:06 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

char	*concat_str(char *src, char* dest)
{
	int	i;
	int	dest_length;
	
	dest_length = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i + dest_length] = src[i];
		i++;
	}
	dest[i + dest_length] = '\0';
	return (dest);
}

int	calcul_full_length(int size, char **strs, char *sep)
{
	int	i;
	int	total_length;
	
	i = 0;
	total_length = 0;
	while (i < size)
	{
		total_length += ft_strlen(strs[i]);
		i++;
	}
	total_length += ft_strlen(sep);
	return (total_length);
}

char *ft_strjoin(int size, char **strs, char *sep)
{
	int	i;
	char	*str;
	int	full_length;

	i = 0;
	if (!size)
		return (malloc(0));
	full_length = calcul_full_length(size, strs, sep);
	str = malloc(full_length + 1);
	while(i < size)
	{
		concat_str(strs[i], str);
		if (i != size + 1)
			concat_str(sep, str);
		i++;
	}
	str[full_length] = '\0';
	return (str);
}
