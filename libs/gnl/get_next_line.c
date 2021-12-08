/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 04:59:11 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/19 18:38:59 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_eol(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

int	gnl_strlen(char *s)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*my_strjoin(char *s1, char *s2, int lens2)
{
	char	*str;
	int		lens1;
	int		i;

	lens1 = gnl_strlen(s1);
	str = malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < lens1 + lens2)
	{
		if (i < lens1)
			str[i] = s1[i];
		else
			str[i] = s2[i - lens1];
		i++;
	}
	str[i] = '\0';
	if (s1)
		free(s1);
	return (str);
}

int	check_for_content(char *str)
{
	int		i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] != '\0')
			return (1);
		i++;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char		*formatted_buff;
	char			buff[BUFFER_SIZE];
	int				bytes_read;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	bytes_read = 42;
	while (!check_eol(formatted_buff))
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (-1);
		formatted_buff = my_strjoin(formatted_buff, buff, bytes_read);
		if (!check_for_content(formatted_buff) && bytes_read == 0)
			return (-2);
	}
	*line = get_line(formatted_buff);
	formatted_buff = get_formatted_buff(formatted_buff);
	if (bytes_read == 0)
		return (0);
	return (1);
}
