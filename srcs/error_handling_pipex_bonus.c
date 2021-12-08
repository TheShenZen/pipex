/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_pipex_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 02:54:33 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/29 16:41:41 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	handle_error(t_pipex *p)
{
	free_struct_bonus(p->pids, p->link, p->path, p->cmds);
	if (p->here_doc)
		unlink(".here_doc");
	perror("bash : ");
	exit(EXIT_FAILURE);
}

void	handle_cmd_not_found(t_pipex *p, int index)
{
	char		*tmp;

	tmp = ft_strjoin(p->cmds[index][0], " : command not found\n");
	if (tmp == NULL)
		handle_error(p);
	ft_putstr_fd(tmp, STDERR_FILENO);
	free(tmp);
	free_struct_bonus(p->pids, p->link, p->path, p->cmds);
	errno = 0;
	exit(EXIT_FAILURE);
}
