/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:38:15 by amura             #+#    #+#             */
/*   Updated: 2023/08/25 12:13:12 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str);

int main(void)
{

	printf("%d\n", ft_atoi("12345")); // Attendu : 12345
	printf("%d\n", ft_atoi("   5678")); // Attendu : 5678
	printf("%d\n", ft_atoi("---+--+1234")); // Attendu : -1234
	printf("%d\n", ft_atoi("00000456")); // Attendu : 456
	printf("%d\n", ft_atoi("-789")); // Attendu : -789
	printf("%d\n", ft_atoi("1234ab567")); // Attendu : 1234
	printf("%d\n", ft_atoi("   +---+")); // Attendu : 0
	printf("%d\n", ft_atoi("\t\n\v\f\r 42")); // Attendu : 42
	printf("%d\n", ft_atoi("99999999999999999999")); // Indéfini
	printf("%d\n", ft_atoi("")); // Attendu : 0
	printf("%d\n", ft_atoi(" ---+-jshda")); // Attendu : 0
	printf("\n");
	printf("%d\n", atoi("12345")); // Attendu : 12345
	printf("%d\n", atoi("   5678")); // Attendu : 5678
	printf("%d\n", atoi("---+--+1234")); // Attendu : -1234
	printf("%d\n", atoi("00000456")); // Attendu : 456
	printf("%d\n", atoi("-789")); // Attendu : -789
	printf("%d\n", atoi(" ---+--+1234ab567")); // Attendu : 1234
	printf("%d\n", atoi("   +---+")); // Attendu : 0
	printf("%d\n", atoi("\t\n\v\f\r 42")); // Attendu : 42
	printf("%d\n", atoi("99999999999999999999")); // Indéfini
	printf("%d\n", atoi("")); // Attendu : 0

	return 0;
}
