/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 04:59:54 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/19 18:35:39 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <unistd.h>
# include <stdlib.h>

int		gnl_strlen(char *s);
char	*get_line(char *s);
char	*get_formatted_buff(char *s);
int		check_eol(char *s);
char	*my_strjoin(char *s1, char *s2, int lens2);
int		get_next_line(int fd, char **line);

#endif
