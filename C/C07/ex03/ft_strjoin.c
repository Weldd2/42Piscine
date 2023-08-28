/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:10:12 by amura             #+#    #+#             */
/*   Updated: 2023/08/28 22:22:19 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*concat_str(char *src, char *dest)
{
	int	i;
	int	dest_length;

	dest_length = ft_strlen(dest);
	i = -1;
	while (src[++i] != '\0')
		dest[i + dest_length] = src[i];
	dest[i + dest_length] = '\0';
	return (dest);
}

int	get_full_length(int size, char **strs)
{
	int	i;
	int	r;

	i = -1;
	while (++i < size)
		r += ft_strlen(strs[i]);
	return (r);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str;

	if (!size)
		return (malloc(0));
	str = malloc(get_full_length(size, strs));
	i = -1;
	while (++i < size)
	{
		concat_str(strs[i], str);
		if (i != size - 1)
			concat_str(sep, str);
	}
	return (str);
}
