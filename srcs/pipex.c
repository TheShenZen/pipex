/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:50:13 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/29 16:29:57 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	in_create_child(int i, t_pipex *p, char **ev)
{
	if (pipe(p->link[i]) < 0)
		handle_error(p);
	p->pids[i] = fork();
	if (p->pids[i] < 0)
		handle_error(p);
	else if (p->pids[i] == 0)
	{
		if (p->fds[0] < 0)
			handle_error(p);
		close(p->link[i][0]);
		close(p->fds[1]);
		dup2(p->fds[0], STDIN_FILENO);
		dup2(p->link[i][1], STDOUT_FILENO);
		close(p->link[i][1]);
		close(p->fds[0]);
		execve(find_cmd_path(p, i), p->cmds[i], ev);
		handle_error(p);
	}
	else
	{
		if (p->fds[0] >= 0)
			close(p->fds[0]);
		close(p->link[i][1]);
	}
}

static void	out_create_child(int i, t_pipex *p, char **ev)
{
	p->pids[i] = fork();
	if (p->pids[i] < 0)
		handle_error(p);
	else if (p->pids[i] == 0)
	{
		if (p->fds[1] < 0)
			handle_error(p);
		dup2(p->link[i - 1][0], STDIN_FILENO);
		dup2(p->fds[1], STDOUT_FILENO);
		close(p->link[i - 1][0]);
		close(p->fds[1]);
		execve(find_cmd_path(p, i), p->cmds[i], ev);
		handle_error(p);
	}
	else
	{
		close(p->fds[1]);
		close(p->link[i - 1][0]);
	}
}

static void	create_child(int i, t_pipex *p, char **ev)
{
	p->pids[i] = fork();
	if (p->pids[i] < 0)
		handle_error(p);
	else if (p->pids[i] == 0)
	{
		dup2(p->link[i - 1][0], STDIN_FILENO);
		dup2(p->link[i][1], STDOUT_FILENO);
		close(p->link[i - 1][0]);
		close(p->link[i][1]);
		execve(find_cmd_path(p, i), p->cmds[i], ev);
		handle_error(p);
	}
	else
	{
		close(p->link[i - 1][0]);
		close(p->link[i][1]);
	}
}

static void	pipex(t_pipex *p, char **ev)
{
	int		i;

	i = 0;
	while (p->cmds[i] != NULL)
	{
		if (i == 0)
			in_create_child(i, p, ev);
		else if (p->cmds[i + 1] == NULL)
			out_create_child(i, p, ev);
		else
			create_child(i, p, ev);
		++i;
	}
	i = 0;
	while (p->cmds[i] != NULL)
	{
		waitpid(p->pids[i], NULL, 0);
		++i;
	}
}

int	main(int ac, char **av, char **ev)
{
	t_pipex	p;

	if (ac != 5 && BONUS == 0)
	{
		ft_putstr_fd("Wrong number of arguments.\n", STDERR_FILENO);
		return (-1);
	}
	else if (ev == NULL)
	{
		ft_putstr_fd("No env.\n", STDERR_FILENO);
		return (-1);
	}
	init_pipex(&p, ac, av, ev);
	pipex(&p, ev);
	close_all(&p);
	free_struct(&p);
	return (0);
}
