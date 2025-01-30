/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:20:53 by isegura-          #+#    #+#             */
/*   Updated: 2024/10/04 13:57:22 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;
	char	cc;

	cc = (char) c;
	size = ft_strlen(s);
	while (size != 0)
	{
		if (s[size] == cc)
			return ((char *) &s[size]);
		size--;
	}
	if (s[size] == cc)
		return ((char *) &s[size]);
	return (NULL);
}
