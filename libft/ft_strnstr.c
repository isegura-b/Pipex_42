/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:12:16 by isegura-          #+#    #+#             */
/*   Updated: 2024/10/04 13:53:50 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *) big);
	while (big[i] != '\0' && i < len)
	{
		while (big[i + j] == little[j])
		{
			if (big[i + j] == '\0' || (i + j) == len)
				break ;
			j++;
			if (little[j] == '\0')
				return ((char *) &big[i]);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
