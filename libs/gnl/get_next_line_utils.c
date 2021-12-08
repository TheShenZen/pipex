/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 05:35:03 by seciurte          #+#    #+#             */
/*   Updated: 2021/11/19 19:27:58 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *s)
{
	char	*str;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_formatted_buff(char *s)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (i == gnl_strlen(s))
	{
		free(s);
		return (NULL);
	}
	len = gnl_strlen(&s[++i]);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	j = 0;
	while (j < len)
		str[j++] = s[i++];
	str[j] = '\0';
	free(s);
	return (str);
}
