/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:05:59 by seciurte          #+#    #+#             */
/*   Updated: 2021/04/09 13:44:06 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	nbr_len(long long n, int base_len)
{
	int		i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n /= base_len;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(long long n, char *base)
{
	char		*str;
	int			n_len;
	int			base_len;
	int			tmp;

	base_len = ft_strlen(base);
	n_len = nbr_len(n, base_len);
	str = malloc(sizeof(char) * n_len + 1);
	if (str == NULL)
		return (NULL);
	str[n_len] = '\0';
	while (--n_len >= 0)
	{
		tmp = (n % base_len);
		if (tmp < 0)
			tmp *= -1;
		str[n_len] = base[tmp];
		n /= base_len;
	}
	return (str);
}
