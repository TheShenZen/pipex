/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 01:40:18 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/29 16:24:11 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include "libft.h"
# include "get_next_line.h"

# ifndef BONUS
#  define BONUS 0
# endif

typedef struct s_pipex
{
	int		fds[2];
	int		*pids;
	int		**link;
	char	**path;
	char	***cmds;
}				t_pipex;

char	**get_path(char **env);
char	***get_cmds(char **av);
char	*find_cmd_path(t_pipex *p, int c);
void	free_struct(t_pipex *p);
void	handle_error(t_pipex *p);
void	handle_cmd_not_found(t_pipex *p, int index);
void	init_pipex(t_pipex *p, int ac, char**av, char **ev);
void	close_all(t_pipex *p);

#endif