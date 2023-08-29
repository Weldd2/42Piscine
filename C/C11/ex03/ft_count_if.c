/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:27:44 by amura             #+#    #+#             */
/*   Updated: 2023/08/29 21:31:41 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:19:10 by amura             #+#    #+#             */
/*   Updated: 2023/08/29 21:26:50 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	while (++i < length)
	{
		if (f(tab[i]))
			j++;
	}
	return (j);
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

