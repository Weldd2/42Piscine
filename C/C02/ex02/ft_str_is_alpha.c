/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:46:18 by amura             #+#    #+#             */
/*   Updated: 2023/08/14 10:44:42 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	compteur;

	compteur = 0;
	while (str[compteur])
	{
		if ((str[compteur] < 'A' || str[compteur] > 'Z') 
			&& (str[compteur] < 'a' || str[compteur] > 'z'))
		{
			return (0);
		}
		compteur++;
	}
	return (1);
}
