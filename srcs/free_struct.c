/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:50:14 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/26 12:54:43 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_path(t_pipex *p)
{
	int			i;

	i = 0;
	if (p->path != NULL)
		while (p->path[i] != NULL)
			free(p->path[i++]);
	free(p->path);
}

static void	free_cmds(t_pipex *p)
{
	int			i;
	int			j;

	i = 0;
	if (p->cmds != NULL)
	{
		while (p->cmds[i] != NULL)
		{
			j = 0;
			while (p->cmds[i][j] != NULL)
				free(p->cmds[i][j++]);
			free(p->cmds[i++]);
		}
	}
	free(p->cmds);
}

static void	free_pids(t_pipex *p)
{
	free(p->pids);
}

static void	free_link(t_pipex *p)
{
	int		i;

	i = 0;
	if (p->link != NULL)
		while (p->link[i] != NULL)
			free(p->link[i++]);
	free(p->link);
}

void	free_struct(t_pipex *p)
{
	free_path(p);
	free_pids(p);
	free_cmds(p);
	free_link(p);
}
