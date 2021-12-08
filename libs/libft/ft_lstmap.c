/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:51:16 by seciurte          #+#    #+#             */
/*   Updated: 2021/04/01 19:49:54 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list		*new;
	t_list		*curr_new;
	t_list		*curr_lst;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (new == NULL)
		return (NULL);
	curr_new = new;
	curr_lst = lst->next;
	while (curr_lst)
	{
		curr_new->next = ft_lstnew(f(curr_lst->content));
		if (curr_new == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		curr_new = curr_new->next;
		curr_lst = curr_lst->next;
	}
	return (new);
}
