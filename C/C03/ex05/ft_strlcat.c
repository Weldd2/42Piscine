/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:04:37 by amura             #+#    #+#             */
/*   Updated: 2023/08/16 10:19:34 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_length;
	unsigned int	src_length;

	src_length = 0;
	dest_length = 0;
	i = 0;
	while (dest[dest_length])
		dest_length++;
	while (src[src_length])
		src_length++;
	if (size == 0)
		return (src_length);
	while (src[i] != '\0' && (dest_length + i) < size - 1)
	{
		dest[dest_length + i] = src[i];
		i++;
	}
	dest[i + dest_length] = '\0';
	return (dest_length + src_length);
}
