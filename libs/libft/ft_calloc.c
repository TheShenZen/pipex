/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:16:05 by seciurte          #+#    #+#             */
/*   Updated: 2021/04/01 18:15:59 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*el;

	el = malloc(size * nmemb);
	if (el == NULL)
		return (NULL);
	if ((size * nmemb) != 0)
		ft_bzero(el, (nmemb * size));
	return (el);
}
