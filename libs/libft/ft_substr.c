/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:43:27 by seciurte          #+#    #+#             */
/*   Updated: 2021/04/01 19:54:59 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		sub = malloc(sizeof(char));
		if (sub == NULL)
			return (NULL);
		*sub = '\0';
		return (sub);
	}
	sub = malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, s + start, (len + 1));
	return (sub);
}
