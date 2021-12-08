/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:29:02 by seciurte          #+#    #+#             */
/*   Updated: 2020/11/25 19:39:17 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*current;
	t_list		*next;

	current = (*lst);
	while (current != NULL)
	{
		del(current->content);
		next = current->next;
		free(current);
		current = next;
	}
	(*lst) = NULL;
}
