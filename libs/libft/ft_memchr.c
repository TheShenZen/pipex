/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:27:01 by seciurte          #+#    #+#             */
/*   Updated: 2021/04/01 18:25:09 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s1, int c, size_t n)
{
	unsigned char	*s;

	s = (unsigned char *)s1;
	while (n--)
	{
		if (*s == (unsigned char)c)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
