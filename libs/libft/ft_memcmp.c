/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:12:48 by seciurte          #+#    #+#             */
/*   Updated: 2021/04/01 18:24:45 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cpy1;
	unsigned char	*cpy2;

	cpy1 = (unsigned char *)s1;
	cpy2 = (unsigned char *)s2;
	while (n--)
	{
		if (*cpy1 != *cpy2)
			return (*cpy1 - *cpy2);
		cpy1++;
		cpy2++;
	}
	return (0);
}
