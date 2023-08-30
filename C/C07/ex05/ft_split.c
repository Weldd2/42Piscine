/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:28:11 by amura             #+#    #+#             */
/*   Updated: 2023/08/30 02:48:53 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	char_in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (char_in_charset(*str, charset))
			i++;
		str++;
	}
	return (i + 1);
}

void	ft_fill_word(char **r, char **str, char *charset)
{
	char	*r_start;

	r_start = *r;
	while (**str && !char_in_charset(**str, charset))
	{
		**r = **str;
		(*str)++;
		(*r)++;
	}
	**r = '\0';
	*r = r_start;
	while (**str && char_in_charset(**str, charset))
		(*str)++;
}

int	ft_wordlen(char *str, char *charset)
{
	int	len;

	len = 0;
	while (*str && !char_in_charset(*str, charset))
	{
		len++;
		str++;
	}
	return (len);
}

char	**ft_split(char *str, char *charset)
{
	char	**r;
	char	**r_cpy;

	r = malloc((count_words(str, charset) + 1) * sizeof(char *));
	if (!r)
		return (NULL);
	r_cpy = r;
	while (*str)
	{
		*r = malloc(ft_wordlen(str, charset) + 1);
		if (!*r)
			return (NULL);
		ft_fill_word(r, &str, charset);
		if (*str)
			r++;
	}
	*(r + 1) = NULL;
	return (r_cpy);
}
