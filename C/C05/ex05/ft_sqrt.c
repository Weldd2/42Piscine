/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:51:18 by amura             #+#    #+#             */
/*   Updated: 2023/08/24 18:35:46 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	result;
	int	tmp;

	if (nb <= 0)
		return (0);
	result = nb;
	tmp = 0;
	while (result != tmp)
	{
		tmp = result;
		result = (nb / tmp + tmp) / 2;
	}
	if (result * result != nb)
		return (0);
	return (result);
}
