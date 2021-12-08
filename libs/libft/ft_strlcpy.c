/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:39:13 by seciurte          #+#    #+#             */
/*   Updated: 2021/04/01 19:53:42 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		s_src;

	if (!dst && !src)
		return (0);
	i = 1;
	s_src = ft_strlen(src);
	while (*src && i < size)
	{
		*dst = *src;
		src++;
		dst++;
		i++;
	}
	if (size != 0)
		*dst = '\0';
	return (s_src);
}
