/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:51:55 by amura             #+#    #+#             */
/*   Updated: 2023/08/16 10:26:46 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int				i;
	unsigned int	dest_length;

	i = 0;
	dest_length = 0;
	while (dest[dest_length])
		dest_length++;
	while (src[i] != '\0')
	{
		dest[i + dest_length] = src[i];
		i++;
	}
	dest[i + dest_length] = '\0';
	return (dest);
}
