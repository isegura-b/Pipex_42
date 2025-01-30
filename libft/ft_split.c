/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:32:27 by isegura-          #+#    #+#             */
/*   Updated: 2024/10/02 17:13:02 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **save, int j)
{
	while (j > 0)
	{
		j--;
		free(save[j]);
	}
	free(save);
	return (NULL);
}

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;
	int	sw;

	i = 0;
	count = 0;
	sw = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && sw == 0)
		{
			count++;
			sw = 1;
		}
		if (s[i] == c)
			sw = 0;
		i++;
	}
	return (count);
}

static int	ft_count_char(char const *s, char c, int i)
{
	int	char_count;

	char_count = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		char_count++;
		i++;
	}
	return (char_count);
}

static char	**ft_pointer(char const *s, char **save, int w, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < w)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		save[j] = (char *)malloc(sizeof(char) * ft_count_char(s, c, i) + 1);
		if (save[j] == NULL)
			return (ft_free(save, j));
		k = 0;
		while (s[i] != '\0' && s[i] != c)
			save[j][k++] = s[i++];
		save[j][k] = '\0';
		j++;
	}
	save[w] = NULL;
	return (save);
}

char	**ft_split(char const *s, char c)
{
	char	**save;
	int		w;

	if (s == NULL)
		return (NULL);
	w = ft_count_words((char *)s, c);
	save = (char **)malloc(sizeof(char *) * (w + 1));
	if (save == NULL)
		return (NULL);
	return (ft_pointer(s, save, w, c));
}
