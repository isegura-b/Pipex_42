/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:27:14 by isegura-          #+#    #+#             */
/*   Updated: 2024/10/04 13:54:23 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*spc;
	size_t			i;

	i = 0;
	spc = malloc (nmemb * size);
	if (!spc)
		return (NULL);
	while (i < (nmemb * size))
	{
		spc[i] = 0;
		i++;
	}
	return (spc);
}
