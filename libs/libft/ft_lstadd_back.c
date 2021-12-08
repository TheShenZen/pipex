/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:37:16 by seciurte          #+#    #+#             */
/*   Updated: 2021/04/01 19:55:28 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	last = *alst;
	if (alst == NULL || new == NULL)
		return ;
	if (last)
	{
		last = ft_lstlast(last);
		last->next = new;
	}
	else
		*alst = new;
}
