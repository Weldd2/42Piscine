/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:36:43 by amura             #+#    #+#             */
/*   Updated: 2023/08/28 17:40:27 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*s;
	int		i;

	i = 0;
	while (src[i])
		i++;
	s = malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	i = -1;
	while (src[++i])
		s[i] = src[i];
	s[i] = '\0';
	return (s);
}
