/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:44:52 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/26 13:04:19 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(char **av, t_pipex *p)
{
	int		rt;
	char	*line;

	rt = 1;
	while (rt > 0)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		rt = get_next_line(STDIN_FILENO, &line);
		if (rt < 0)
		{
			free(line);
			handle_error(p);
		}
		if (ft_strncmp(line, av[2], ft_strlen(av[2])) == 0)
			break ;
		write(p->fds[0], line, ft_strlen(line));
		free(line);
		line = NULL;
	}
	free(line);
	p->fds[0] = open(".here_doc", O_RDONLY);
	if (p->fds[0] < 0)
		handle_error(p);
}
