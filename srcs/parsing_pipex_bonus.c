/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pipex_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 01:45:52 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/26 15:46:27 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**get_path(char **env)
{
	while (*env != NULL && ft_strncmp("PATH", *env, 4) != 0)
		++env;
	return (ft_split(&env[0][5], ':'));
}

char	***get_cmds(char **av, t_pipex *p)
{
	int		i;
	char	***cmds;

	i = 2;
	if (p->here_doc)
		i = 3;
	while (av[i + 1] != NULL)
		++i;
	i -= 1 + p->here_doc;
	cmds = malloc(sizeof(char **) * i);
	if (cmds == NULL)
		return (NULL);
	cmds[--i] = NULL;
	while (--i >= 0)
	{
		cmds[i] = ft_split(av[i + 2 + p->here_doc], ' ');
		if (cmds == NULL)
			return (NULL);
	}
	return (cmds);
}

char	*find_cmd_path(t_pipex *p, int c)
{
	int		i;
	char	*cmd;
	char	*tmp;

	i = 0;
	if (access(p->cmds[c][0], X_OK) == 0)
		return (p->cmds[c][0]);
	while (p->path[i])
	{
		tmp = ft_strjoin(p->path[i], "/");
		if (tmp == NULL)
			return (NULL);
		cmd = ft_strjoin(tmp, p->cmds[c][0]);
		free(tmp);
		if (access(cmd, X_OK) == 0)
			return (cmd);
		else
			free(cmd);
		++i;
	}
	handle_cmd_not_found(p, c);
	return (NULL);
}
