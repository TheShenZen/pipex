/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:00:26 by seciurte          #+#    #+#             */
/*   Updated: 2021/04/01 19:45:32 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*cpy;

	len = ft_strlen(s) + 1;
	cpy = malloc(sizeof(char) * len);
	if (cpy == NULL)
		return (NULL);
	ft_memcpy(cpy, s, len);
	return (cpy);
}
