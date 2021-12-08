/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_pipex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 02:54:33 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/29 16:24:02 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_all(t_pipex *p)
{
	if (p->fds[0] >= 0)
		close(p->fds[0]);
	if (p->fds[1] >= 0)
		close(p->fds[1]);
	if (p->link[0][0] >= 0)
		close(p->link[0][0]);
	if (p->link[0][1] >= 0)
		close(p->link[0][1]);
}

void	handle_error(t_pipex *p)
{
	close_all(p);
	free_struct(p);
	perror("bash : ");
	errno = 0;
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
	close_all(p);
	free_struct(p);
	errno = 0;
	exit(EXIT_FAILURE);
}
