/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:59:30 by amura             #+#    #+#             */
/*   Updated: 2023/08/31 20:11:09 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	str_len;
	int	to_find_len;
	int	i;

	str_len = 0;
	while (str[str_len])
		str_len++;
	to_find_len = 0;
	while (to_find[to_find_len])
		to_find_len++;
	if (to_find_len == 0)
		return ((char *)str);
	i = 0;
	while (i <= str_len - to_find_len)
	{
		if (ft_strcmp(str + i, to_find, to_find_len))
			return ((char *)(str + i));
		i++;
	}
	return ("");
}

