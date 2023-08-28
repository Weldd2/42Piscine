/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:21:28 by amura             #+#    #+#             */
/*   Updated: 2023/08/28 19:26:13 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_p(char *str, char c)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}

int	atoi_base(char *str, char *base, int s, int r)
{
	int	base_l;

	base_l = -1;
	while(base[++base_l]);
	if (((*str >= 7 && *str <= 13) || *str == ' ' ||*str == '+') && r == 0)
		return (atoi_base(str + 1, base, s, r));
	if (*str == '-' && r == 0)
		return (atoi_base(str + 1, base, s * -1, r));
	if (*str <= '9' && *str >= '0')
		return (atoi_base(str + 1, base, s, r * base_l + get_p(base, *str)));
	return (r * s);
}
