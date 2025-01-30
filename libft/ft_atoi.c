/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:40:38 by isegura-          #+#    #+#             */
/*   Updated: 2024/10/07 16:20:23 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	neg;
	int	res;
	int	err;

	err = 0;
	neg = 1;
	res = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	while (*nptr == '+' || *nptr == '-')
	{
		err++;
		if (*nptr == '-')
			neg *= -1 ;
		if (err >= 2)
			return (0);
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (res * neg);
}
/*
int	main (void)
{
	const char	*nptr;
	*nptr = "    -1234";
	printf("%d\n", ft_atoi(nptr));
	return (0);
}*/
