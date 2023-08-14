/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:03:53 by amura             #+#    #+#             */
/*   Updated: 2023/08/14 12:53:52 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    print_hex(unsigned char c)
{
    char *base;

    base = "0123456789abcdef";
    write(1, "\\", 1);
    write(1, &base[c / 16], 1);
    write(1, &base[c % 16], 1);
}

void ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str < ' ' || *str > 126)  // Check if the character is non-printable
		{
			print_hex((unsigned char)*str);
		}
		else
		{
			write(1, str, 1);
		}
		str++;
	}
}
