/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:16:34 by seciurte          #+#    #+#             */
/*   Updated: 2021/04/01 18:48:01 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s) + 1;
	while (len--)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
