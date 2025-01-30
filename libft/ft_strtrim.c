/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:28:16 by isegura-          #+#    #+#             */
/*   Updated: 2024/10/02 17:07:28 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	char		*mem;

	start = 0;
	end = ft_strlen(s1);
	if (s1 == NULL || set == NULL)
		return (NULL);
	end = end - 1;
	while (s1[start] != '\0' && ft_set(s1[start], set) == 1)
		start++;
	while (end > start && ft_set(s1[end], set) == 1)
		end--;
	mem = (char *)malloc(sizeof(char) * (end - start + 2));
	if (mem == NULL)
		return (NULL);
	ft_strlcpy(mem, &s1[start], end - start + 2);
	return (mem);
}
