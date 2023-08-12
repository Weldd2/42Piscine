/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:51:48 by amura             #+#    #+#             */
/*   Updated: 2023/08/11 11:53:03 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	compteur;

	compteur = 0;
	while (str[compteur])
	{
		if (str[compteur] < 31 || str[compteur] > 0)
		{
			return (0);
		}
		compteur++;
	}
	return (1);
}
