/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:19:10 by amura             #+#    #+#             */
/*   Updated: 2023/08/29 21:28:20 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char *))
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (f(tab[i]))
			return (1);
	}
	return (0);
}

int	has_a_a(char *str)
{
	int	i;
	
	i = -1;
	while (str[++i])
	{
		if (str[i] == 'a')
			return (1);
	}
	return (0);
}