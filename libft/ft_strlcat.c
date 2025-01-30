/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:03:45 by isegura-          #+#    #+#             */
/*   Updated: 2024/10/04 13:50:52 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	l_dst;
	size_t	l_src;
	size_t	i;
	size_t	p;

	l_dst = ft_strlen(dst);
	l_src = ft_strlen(src);
	i = 0;
	if (l_dst >= size)
		return (size + l_src);
	p = size - l_dst - 1;
	while ((i < p) && (src[i] != '\0'))
	{
		dst[l_dst + i] = src[i];
		i++;
	}
	dst[l_dst + i] = '\0';
	return (l_dst + l_src);
}
