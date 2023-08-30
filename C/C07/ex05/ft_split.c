#include <stdlib.h>

static int	is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

static int	count_words(char *str, char *charset)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str && !is_sep(*str, charset))
		{
			count++;
			while (*str && !is_sep(*str, charset))
				str++;
		}
	}
	return (count);
}

static char	*make_word(char *str, int len)
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

char		**ft_split(char *str, char *charset)
{
	char	**tab;
	int		word_count;
	int		i;
	int		len;

	word_count = count_words(str, charset);
	tab = malloc((word_count + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*str && is_sep(*str, charset))
			str++;
		len = 0;
		while (str[len] && !is_sep(str[len], charset))
			len++;
		tab[i] = make_word(str, len);
		if (!tab[i])
			return (NULL);
		str += len;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
