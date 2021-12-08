/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:06:29 by seciurte          #+#    #+#             */
/*   Updated: 2021/04/01 19:41:31 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char		*last_el_s;
	char			*last_el_d;

	if (!dest && !src)
		return (NULL);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	else
	{
		last_el_s = src + (n - 1);
		last_el_d = dest + (n - 1);
		while (n--)
			*last_el_d-- = *last_el_s--;
	}
	return (dest);
}
