/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:00:28 by seciurte          #+#    #+#             */
/*   Updated: 2020/11/19 14:25:49 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	while (*nptr && (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r')))
		nptr++;
	if (*nptr && (*nptr == '-' || *nptr == '+'))
		if (*nptr++ == '-')
			sign *= -1;
	while (*nptr && *nptr >= '0' && *nptr <= '9')
		nbr = nbr * 10 + (*nptr++ - '0');
	return (nbr * sign);
}
