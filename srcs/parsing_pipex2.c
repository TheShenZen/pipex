/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pipex2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 13:01:35 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/26 16:28:28 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_pids_storage(t_pipex *p)
{
	int		i;

	i = 0;
	while (p->cmds[i] != NULL)
		++i;
	p->pids = malloc(sizeof(pid_t) * i);
	if (p->pids == NULL)
		handle_error(p);
}

static void	create_pipeline(t_pipex *p)
{
	int		i;

	i = 0;
	while (p->cmds[i] != NULL)
		++i;
	p->link = malloc(sizeof(int *) * i);
	if (p->link == NULL)
		handle_error(p);
	p->link[--i] = NULL;
	while (--i >= 0)
	{
		p->link[i] = malloc(sizeof(int) * 2);
		if (p->link[i] == NULL)
			handle_error(p);
	}
}

static void	set_struct_to_null(t_pipex *p)
{
	p->pids = NULL;
	p->link = NULL;
	p->path = NULL;
	p->cmds = NULL;
}

void	init_pipex(t_pipex *p, int ac, char**av, char **ev)
{
	set_struct_to_null(p);
	p->fds[0] = open(av[1], O_RDONLY);
	p->fds[1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	p->path = get_path(ev);
	if (p->path == NULL)
		handle_error(p);
	p->cmds = get_cmds(av);
	if (p->cmds == NULL)
		handle_error(p);
	create_pipeline(p);
	if (p->link == NULL)
		handle_error(p);
	init_pids_storage(p);
}
