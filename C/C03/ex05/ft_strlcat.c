/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:04:37 by amura             #+#    #+#             */
/*   Updated: 2023/08/15 18:51:45 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	string_length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int	l;
	int	r;
	
	i = 0;
	l = string_length(dest);
	r = string_length(dest) + string_length(src);
	while (src[i] != '\0' && (size -1) > i)
	{
		dest[i + l] = src[i];
		i++;
	}
	dest[i + l] = '\0';
	return (r);
}
