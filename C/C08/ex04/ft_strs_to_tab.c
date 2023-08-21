/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:57:16 by amura             #+#    #+#             */
/*   Updated: 2023/08/21 18:05:05 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char		*s;
	int			i;

	i = 0;
	while (src[i])
		i++;
	s = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src[i])
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

	i = -1;
	tab = malloc(sizeof(t_stock_str) * ac + 1);
	if (!tab)
		return (NULL);
	while (++i < ac)
	{
		tab[i].str = av[i];
		tab[i].size = str_len(av[i]);
		tab[i].copy = ft_strdup(tab[i].str);
	}
	tab[i].str = '\0';
	return (tab);
}
