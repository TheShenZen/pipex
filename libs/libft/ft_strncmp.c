/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 21:13:32 by seciurte          #+#    #+#             */
/*   Updated: 2020/11/26 20:02:19 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;
	size_t			l1;
	size_t			l2;
	size_t			i;

	if (n == 0)
		return (0);
	i = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	while (i <= l1 && i <= l2 && i < n)
	{
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		i++;
		if (c1 != c2)
			return (c1 - c2);
	}
	return (0);
}
