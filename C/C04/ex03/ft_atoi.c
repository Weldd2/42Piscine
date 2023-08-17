/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:43:33 by amura             #+#    #+#             */
/*   Updated: 2023/08/17 16:53:58 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_loop(char *str, int resultat, int signe)
{
	if ((*str <= '\r' && *str >= '\t') || *str == ' ' || *str == '+')
		return (ft_atoi_loop(str + 1, resultat, signe));
	if (*str == '-' && resultat == 0)
		return (ft_atoi_loop(str + 1, resultat, signe * -1));
	if (*str <= '9' && *str >= '0')
		return (ft_atoi_loop(str + 1, (resultat * 10) + (*str - '0'), signe));
	return (resultat * signe);
}

int	ft_atoi(char *str)
{
	return (ft_atoi_loop(str, 0, 1));
}
