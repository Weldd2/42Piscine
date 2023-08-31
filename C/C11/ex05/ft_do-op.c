/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do-op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:26:14 by amura             #+#    #+#             */
/*   Updated: 2023/08/31 22:40:19 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long	addition(long a, long b);
long	soustraction(long nb1, long nb2);
long	multiplication(long nb1, long nb2);
long	division(long nb1, long nb2);
long	modulo(long nb1, long nb2);
long	ft_atoi(char *str);

char	get_ope(char *ope)
{
	long	len;

	len = 0;
	while (ope[len])
		len++;
	if (len != 1)
		return ('\0');
	return (ope[0]);
}

int	main(int argc, char *argv[])
{
	char	ope;
	long	nb1;
	long	nb2;

	if (argc != 4)
		return (0);
	ope = get_ope(argv[2]);
	nb1 = ft_atoi(argv[1]);
	nb2 = ft_atoi(argv[3]);
	if (ope == '+')
		return (addition(nb1, nb2));
	if (ope == '-')
		return (soustraction(nb1, nb2));
	if (ope == '*')
		return (multiplication(nb1, nb2));
	if (ope == '/')
		return (division(nb1, nb2));
	if (ope == '%')
		return (modulo(nb1, nb2));
	write(1, "0\n", 2);
	return (0);
}
