/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:13:16 by amura             #+#    #+#             */
/*   Updated: 2023/08/27 11:13:20 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoi_loop(char *str, int resultat, int signe)
{
	if (((*str <= '\r' && *str >= '\t') || *str == ' ' || *str == '+') 
		&& resultat == 0)
		return (ft_atoi_loop(str + 1, resultat, signe));
	if (*str == '-' && resultat == 0)
		return (ft_atoi_loop(str + 1, resultat, signe * -1));
	if (*str <= '9' && *str >= '0')
		return (ft_atoi_loop(str + 1, (resultat * 10) + (*str - '0'), signe));
	return (resultat * signe);
}

long long	ft_atoi(char *str)
{
	return (ft_atoi_loop(str, 0, 1));
}
