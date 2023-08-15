/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:05:00 by amura             #+#    #+#             */
/*   Updated: 2023/08/15 16:58:53 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] > 'Z' || str[i] < 'A'))
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

int	is_lowercase(char c)
{
	if (c > 'z' || c < 'a')
	{
		return (0);
	}
	return (1);
}

int	is_alphanumeric(char c)
{
	if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z') && (c < '0' || c > '9'))
	{
		return (0);
	}
	return (1);
}

char	strupcase(char c)
{
	if (is_lowercase(c))
	{
		c -= 32;
	}
	return (c);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	strlowcase(str);
	while (str[i])
	{
		if (i == 0)
		{
			str[i] = strupcase(str[i]);
		}
		else
		{
			if (!is_alphanumeric(str[i - 1]))
			{
				str[i] = strupcase(str[i]);
			}
		}
		i++;
	}
	return (str);
}
