/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:33:12 by amura             #+#    #+#             */
/*   Updated: 2023/08/31 18:03:25 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	is_sep(char c, char *charset)
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
	int	count;
	int	found;

	count = 0;
	found = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str && !is_sep(*str, charset))
		{
			found = 1;
			count++;
			while (*str && !is_sep(*str, charset))
				str++;
		}
	}
	if (found)
		return (count);
	return (1);
}

char	*make_word(char *str, int len)
{
	char	*word;
	int		i;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	split_words(char **tab, char *str, char *charset)
{
	int	i;
	int	len;

	i = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		len = 0;
		while (str[len] && !is_sep(str[len], charset))
			len++;
		if (len > 0)
			tab[i++] = make_word(str, len);
		str += len;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		word_count;

	word_count = count_words(str, charset);
	tab = malloc((word_count + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	split_words(tab, str, charset);
	tab[word_count] = 0;
	return (tab);
}