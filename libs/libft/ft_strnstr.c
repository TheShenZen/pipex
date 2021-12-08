/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 21:14:27 by seciurte          #+#    #+#             */
/*   Updated: 2020/11/28 08:25:40 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t			l;

	if (*s2 == '\0')
		return ((char *)s1);
	l = ft_strlen(s2);
	while (*s1 && len)
	{
		if (*s1 == *s2)
			if (len >= l && ft_strncmp(s1, s2, l) == 0)
				return ((char *)s1);
		s1++;
		len--;
	}
	return (NULL);
}
