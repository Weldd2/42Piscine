/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:28:52 by amura             #+#    #+#             */
/*   Updated: 2023/08/25 10:40:39 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int		main(void)
{
	char			dest[50] = "42 is ";
	char			src[] = "the answer";
	unsigned int	size = 50;
	unsigned int	result;

	result = ft_strlcat(dest, src, size);
	printf("Résultat : %u\n", result);
	printf("Chaîne concaténée : %s\n", dest);
	return (0);
}
