/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:50:16 by seciurte          #+#    #+#             */
/*   Updated: 2021/04/01 19:39:31 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbrlen(long nbr)
{
	int	len;

	len = 1;
	nbr /= 10;
	while (nbr != 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nbr;
	char	*str;

	nbr = (long)n;
	len = nbrlen(nbr) + 1;
	if (nbr < 0)
		len = nbrlen(nbr) + 2;
	str = malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	str[--len] = '\0';
	while (len > 0 && str[--len] != '-')
	{
		str[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
