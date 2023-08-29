/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:28:11 by amura             #+#    #+#             */
/*   Updated: 2023/08/29 16:56:29 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	char_in_charset(char c, char *charset)
{
	while(*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}
int	count_words(char *str, char *charset)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		if(char_in_charset(*str, charset))
			i++;
		str++;
	}
	return (i + 1);
}

char	**ft_split(char *str, char *charset)
{
	char	**r;
	char	**r_cpy;
	int		str_len;

	r = malloc(count_words(str, charset) * sizeof(char *));
	r_cpy = r;
	while (*str != '\0')
	{
		str_len = -1;
		while (str[++str_len])
			;
		*r = malloc(str_len);
		while (!char_in_charset(*str, charset))
		{
			**r = *str;
			str++;
			(*r)++;
		}
		**r = '\0';
		str++;
		r++;
	}
	*r = NULL;
	return (r_cpy);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	print_split_strings(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		free(tab[i]);
		i++;
	}
	free(tab);
}

#include <stdio.h>

int	main(void)
{
	// char	**result;
	char	*s;

	s = "hello world this is split";
	ft_putstr("---- Test 1 ----\n");
	printf("%d\n", count_words(s, " "));
	// result = ft_split(s, " ");
	// print_split_strings(result);

	return (0);
}
