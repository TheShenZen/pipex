/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:50:14 by seciurte          #+#    #+#             */
/*   Updated: 2021/09/08 12:32:58 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_path(char **path)
{
	int			i;

	i = 0;
	if (path != NULL)
	{
		while (path[i] != NULL)
		{
			free(path[i]);
			++i;
		}
	}
	free(path);
}

static void	free_cmds(char ***cmds)
{
	int			i;
	int			j;

	i = 0;
	if (cmds != NULL)
	{
		while (cmds[i] != NULL)
		{
			j = 0;
			while (cmds[i][j] != NULL)
				free(cmds[i][j++]);
			free(cmds[i++]);
		}
	}
	free(cmds);
}

static void	free_pids(int *pids)
{
	free(pids);
}

static void	free_link(int **link)
{
	int		i;

	i = 0;
	if (link != NULL)
		while (link[i] != NULL)
			free(link[i++]);
}

void	free_struct_bonus(int *pids, int **link, char **path, char ***cmds)
{
	free_path(path);
	free_pids(pids);
	free_cmds(cmds);
	free_link(link);
}
