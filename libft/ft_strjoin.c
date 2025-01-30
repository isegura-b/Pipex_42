/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:01:34 by isegura-          #+#    #+#             */
/*   Updated: 2024/10/02 16:51:02 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		s1_len;
	size_t		s2_len;
	char		*mem;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	mem = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (mem == NULL)
		return (NULL);
	while (i < s1_len)
	{
		mem[i] = s1[i];
		i++;
	}
	while (i < s1_len + s2_len)
	{
		mem[i] = s2[i - s1_len];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
