/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:12:03 by amura             #+#    #+#             */
/*   Updated: 2023/08/14 10:24:58 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	compteur;

	compteur = 0;
	while(src[compteur])
	{
		dest[compteur] = src[compteur];
		compteur++;
	}
	dest[compteur] = '\0';
	return (dest);
}
