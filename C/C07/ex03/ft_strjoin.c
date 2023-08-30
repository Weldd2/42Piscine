/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 04:07:17 by amura             #+#    #+#             */
/*   Updated: 2023/08/30 10:49:44 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_total_len(int size, char **strs, char *sep)
{
	int	i;
	int	total_len;

	i = 0;
	total_len = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		i++;
	}
	total_len += ft_strlen(sep) * (size - 1);
	return (total_len);
}

static void	ft_strcat(char *dest, char *src)
{
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

static void	concat_strings(char *result, char **strs, char *sep, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < size - 1)
			ft_strcat(result, sep);
		i++;
	}
}

char		*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		total_len;

	if (size == 0)
	{
		result = malloc(1);
		if (!result)
			return (NULL);
		*result = '\0';
		return (result);
	}
	total_len = ft_total_len(size, strs, sep);
	result = malloc(total_len + 1);
	if (!result)
		return (NULL);
	*result = '\0';
	concat_strings(result, strs, sep, size);
	return (result);
}
#include <stdio.h>

// Mettez ici la définition de votre fonction ft_strjoin

int main(void)
{
	char *strs1[] = {"Hello", "World", "42"};
	char *sep1 = " ";
	char *result1 = ft_strjoin(0, strs1, sep1);
	if (result1)
	{
		printf("Test 1: %s\n", result1);
		free(result1);
	}

	char *strs2[] = {"One", "Two", "Three"};
	char *sep2 = ", ";
	char *result2 = ft_strjoin(3, strs2, sep2);
	if (result2)
	{
		printf("Test 2: %s\n", result2);
		free(result2);
	}

	char *strs3[] = {"OnlyOne"};
	char *sep3 = "";
	char *result3 = ft_strjoin(1, strs3, sep3);
	if (result3)
	{
		printf("Test 3: %s\n", result3);
		free(result3);
	}

	char *result4 = ft_strjoin(0, NULL, "");
	if (result4)
	{
		printf("Test 4: %s\n", result4);
		free(result4);
	}

	return (0);
}
