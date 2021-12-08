/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 01:40:18 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/29 16:41:46 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
	int		here_doc;
	int		fds[2];
	pid_t	*pids;
	int		**link;
	char	**path;
	char	***cmds;
}				t_pipex;

char	**get_path(char **env);
char	***get_cmds(char **av, t_pipex *p);
char	*find_cmd_path(t_pipex *p, int c);
void	free_struct_bonus(int *pids, int **link, char **path, char ***cmds);
void	handle_error(t_pipex *p);
void	handle_cmd_not_found(t_pipex *p, int index);
void	init_pipex(t_pipex *p, int ac, char**av, char **ev);
void	here_doc(char **av, t_pipex *p);

#endif